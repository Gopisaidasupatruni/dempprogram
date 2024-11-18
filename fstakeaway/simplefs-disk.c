#include "simplefs-disk.h"

int DISK_FD;   // pointer to simplefs.txt
struct filehandle_t file_handle_array[MAX_OPEN_FILES]; // Array for storing opened files
/*simplefs_readsuperblock:read the superblock from disk into the superblock_t structure */
void simplefs_readSuperBlock(struct superblock_t *superblock){
    /*
	    Helper function to read superblock from disk into superblock_t structure
	*/
    char tempBuf[BLOCKSIZE];
	/* Move the file descriptor's position to the start of the disk (lseek to offset 0). */
    lseek(DISK_FD, 0, SEEK_SET);
       /* Read block of data (BLOCKSIZE) into the temporary buffer from the disk. */
    int ret = read(DISK_FD ,tempBuf, BLOCKSIZE);
        /* to ensure the entire block was read. */
    assert(ret == BLOCKSIZE);
       /* Copy the contents of the temporary buffer into the provided superblock_t structure. */
    memcpy(superblock, tempBuf, sizeof(struct superblock_t));
}
/* simplefs_writeSuperBlock:write the superblock from the superblock_t structure back to the disk. */
void simplefs_writeSuperBlock(struct superblock_t *superblock){
    /*
	    Helper function to write superblock from superblock_t structure to disk
	*/
    char tempBuf[BLOCKSIZE];
	/* Copy the contents of the superblock_t structure into a temporary buffer. */
    memcpy(tempBuf, superblock, sizeof(struct superblock_t));
    lseek(DISK_FD, 0, SEEK_SET);
        /* Write one block of data (BLOCKSIZE) from the buffer to the disk.*/
    int ret = write(DISK_FD ,tempBuf, BLOCKSIZE);
    assert(ret == BLOCKSIZE);
}
/* simplefs_formatDisk:Format the filesystem and initialize the superblock, inodes, 
        and file handler array with default values.*/
void simplefs_formatDisk(){
    /*
	    Format filesystem and initialise superblock and inodes with default values
    */

    FILE* fp;
    fp = fopen("simplefs", "w+");
    DISK_FD = fileno(fp); /* Retrieve the file descriptor for the disk */

    /* Setting up superblock */
    struct superblock_t *superblock = (struct superblock_t *)malloc(sizeof(struct superblock_t));
    /* Set the disk name in the superblock */
    memcpy(superblock->name, "simplefs", 8);
    /* Mark all inodes as free in the superblock's inode freelist */
    for(int i=0; i<NUM_INODES; i++)
        superblock->inode_freelist[i] = INODE_FREE;
    /* Mark all data blocks as free in the superblock's data block freelist*/
    for(int i=0; i<NUM_DATA_BLOCKS; i++){
        superblock->datablock_freelist[i] = DATA_BLOCK_FREE;
    }
    /*Write the initialized superblock to the disk*/
    simplefs_writeSuperBlock(superblock);
    free(superblock);
    
    // Setting up inode structure
    struct inode_t *inode = (struct inode_t *)malloc(sizeof(struct inode_t));
    /* Set default values for an inode */
    memcpy(inode->name, "", 1);
    inode->status = INODE_FREE;
    inode->file_size = 0;
    /* Initialize all direct blocks to -1 */
    for(int i=0; i<MAX_FILE_SIZE; i++)
        inode->direct_blocks[i] = -1;
    /* Write this default inode to all inode slots on the disk */
    for(int i=0; i<NUM_INODES; i++)
        simplefs_writeInode(i, inode);
    free(inode);

    // Formatting file handler array
    for(int i=0; i<MAX_OPEN_FILES; i++){
        file_handle_array[i].inode_number = -1;
        file_handle_array[i].offset = 0;
    }
}

int simplefs_allocInode(){
    /*
	    Iterate over `inode_freelist` and return index of first empty inode
	*/
    struct superblock_t *superblock = (struct superblock_t *)malloc(sizeof(struct superblock_t));
    simplefs_readSuperBlock(superblock);
    for(int i=0; i<NUM_INODES; i++){
        if(superblock->inode_freelist[i] == INODE_FREE){
		/* Mark the inode as in-use */
            superblock->inode_freelist[i] = INODE_IN_USE;
            simplefs_writeSuperBlock(superblock);
            free(superblock);
            return i;
        }
    }
    free(superblock);
    return -1;
}

void simplefs_freeInode(int inodenum){
    /*
	    free inode with index `inodenum`     
	*/
    assert(inodenum < NUM_INODES);
    struct superblock_t *superblock = (struct superblock_t *)malloc(sizeof(struct superblock_t));
    struct inode_t *inode = (struct inode_t *)malloc(sizeof(struct inode_t));
    simplefs_readSuperBlock(superblock);
    simplefs_readInode(inodenum, inode);
    assert(superblock->inode_freelist[inodenum] == INODE_IN_USE);
    /*  Mark the inode as free in the superblock */
    superblock->inode_freelist[inodenum] = INODE_FREE;
    inode->status = INODE_FREE;
    inode->file_size = 0;
    for (int i = 0; i < MAX_FILE_SIZE; i++)
	    /* Reset all direct block pointers */
        inode->direct_blocks[i] = -1;
    simplefs_writeSuperBlock(superblock);
    simplefs_writeInode(inodenum, inode);
    free(inode);
    free(superblock);
}

void simplefs_readInode(int inodenum, struct inode_t *inodeptr){
    /*
	    read inode with index `inodenum` from disk into `inodeptr`     
	*/
    assert(inodenum < NUM_INODES);
    char tempBuf[BLOCKSIZE / NUM_INODES_PER_BLOCK];
    lseek(DISK_FD, BLOCKSIZE + inodenum * sizeof(struct inode_t), SEEK_SET);
    int ret = read(DISK_FD, tempBuf, sizeof(struct inode_t));
    assert(ret == sizeof(struct inode_t));
    memcpy(inodeptr, tempBuf, sizeof(struct inode_t));
}

void simplefs_writeInode(int inodenum, struct inode_t *inodeptr){
    /*
	    write `inodeptr` to inode with index `inodenum` on disk    
	*/
    assert(inodenum < NUM_INODES);
    char tempBuf[BLOCKSIZE / NUM_INODES_PER_BLOCK];
    memcpy(tempBuf, inodeptr, sizeof(struct inode_t));
    lseek(DISK_FD, BLOCKSIZE + inodenum * sizeof(struct inode_t), SEEK_SET);
    int ret = write(DISK_FD, tempBuf, sizeof(struct inode_t));
    assert(ret == sizeof(struct inode_t));
}

int simplefs_allocDataBlock(){
    /*
	    Iterate over `datablock_freelist` and return index of first empty inode
	*/
    struct superblock_t *superblock = (struct superblock_t *)malloc(sizeof(struct superblock_t));
    simplefs_readSuperBlock(superblock);
    for (int i = 0; i < NUM_DATA_BLOCKS; i++){
        if (superblock->datablock_freelist[i] == DATA_BLOCK_FREE){
            superblock->datablock_freelist[i] = DATA_BLOCK_USED;
            simplefs_writeSuperBlock(superblock);
            free(superblock);
            return i;
        }
    }
    free(superblock);   
    return -1;
}

void simplefs_freeDataBlock(int blocknum){
    /*
	    free data block with index `blocknum`     
	*/
    struct superblock_t *superblock = (struct superblock_t *)malloc(sizeof(struct superblock_t));
    simplefs_readSuperBlock(superblock);
    assert(superblock->datablock_freelist[blocknum] == DATA_BLOCK_USED);
    superblock->datablock_freelist[blocknum] = DATA_BLOCK_FREE;
    simplefs_writeSuperBlock(superblock);
    free(superblock);
}

void simplefs_readDataBlock(int blocknum, char *buf){
    /*
	    read data block with index `blocknum` from disk into `buf`     
	*/
    assert(blocknum < NUM_DATA_BLOCKS);
    char tempBuf[BLOCKSIZE];
    lseek(DISK_FD, BLOCKSIZE*(5 + blocknum), SEEK_SET);
    int ret = read(DISK_FD, tempBuf, BLOCKSIZE);
    memcpy(buf, tempBuf, BLOCKSIZE);
}


void simplefs_writeDataBlock(int blocknum, char *buf){
    /*
	    fill `buf` with data from `blocknum`    
	*/
    assert(blocknum < NUM_DATA_BLOCKS);
    char tempBuf[BLOCKSIZE];
    lseek(DISK_FD, BLOCKSIZE * (5 + blocknum), SEEK_SET);
    memcpy(tempBuf, buf, BLOCKSIZE); 
    int ret = write(DISK_FD, tempBuf, BLOCKSIZE);
    assert(ret == BLOCKSIZE);
}

void simplefs_dump(){
    /*
	    Prints Disk state information   
	*/

   printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<DISK STATE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    struct superblock_t *superblock = (struct superblock_t *)malloc(sizeof(struct superblock_t));
    simplefs_readSuperBlock(superblock);

    /* Print disk name */
    char buf[MAX_NAME_STRLEN + 1];
    buf[MAX_NAME_STRLEN] = '\0';
    memcpy(buf, superblock->name, sizeof(buf) - 1);
    printf("DISK NAME: %s\nINODE FREELIST:\t", buf);

    /*  Print inode freelist */
        for(int i = 0; i < NUM_INODES; i++)
        printf("%c\t", superblock->inode_freelist[i] == INODE_IN_USE ? '1' : 'x'); // Fix freelist display
    
	/* Print data block freelist */
	printf("\nDATA BLOCK FREELIST:\t");
    for(int i = 0; i < NUM_DATA_BLOCKS; i++)
        printf("%c\t", superblock->datablock_freelist[i] == DATA_BLOCK_USED ? '1' : 'x');
    /*for(int i=0; i<NUM_INODES; i++)
        printf("%c\t", superblock->inode_freelist[i]);
    printf("\nDATA BLOCK FREELIST:\t");
    for(int i=0; i<NUM_DATA_BLOCKS; i++)
        printf("%c\t", superblock->datablock_freelist[i]);*/
    printf("\n");

    struct inode_t *inode = (struct inode_t *)malloc(sizeof(struct inode_t));
    for(int i=0; i<NUM_INODES; i++){
        simplefs_readInode(i, inode);
	/* Print details for in-use inodes */
        if(inode->status == INODE_IN_USE){
            printf("INODE %d\nSTATUS:\t%c\tNAME\t%s\tSIZE\t%d\tDATABLOCK\t", i, inode->status, inode->name, inode->file_size);
          /* Print the data block indices for the inode */
	    for (int j = 0; j < MAX_FILE_SIZE; j++)
                printf("%d\t", inode->direct_blocks[j]);
            printf("\n");
	    /* Read and print the contents of the associated data blocks */
            for (int j = 0; j < MAX_FILE_SIZE; j++){
                if (inode->direct_blocks[j] != -1 ){ /* if datablock allocated */
                    char tempBuf[BLOCKSIZE+1];
                    tempBuf[BLOCKSIZE] = '\0';
                    simplefs_readDataBlock(inode->direct_blocks[j], tempBuf);
                    printf("DATA BLOCK %d: %s\n", j, tempBuf);
                }
            }
            printf("\n");
        }     
    }
    free(inode);
    free(superblock);
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
}
