#include "simplefs-ops.h"
extern struct filehandle_t file_handle_array[MAX_OPEN_FILES]; /* Array for storing opened files */
int simplefs_create(char *filename){

        /*

           Create file with name `filename` on disk

*/
        if(filename == NULL || strlen(filename) == 0)

        {

                fprintf(stderr,"Error : Invalid filename\n");

                return -1;

        }

        struct inode_t inode;

        /* Check if filename already exists */

        for (int i = 0; i < NUM_INODES; i++) {

                simplefs_readInode(i, &inode);

                if (strcmp(inode.name, filename) == 0) {

                        fprintf(stderr,"Error : filename already exixt\n");
                        return -1;

                }

        }

        /* Allocate inode for the new file */

        int inode_num = simplefs_allocInode();

        if (inode_num == -1) {

                fprintf(stderr,"Error : No free Inodes\n");
                return -1;

        }

        /* Initialize inode structure */

        inode.status = INODE_IN_USE;

        strncpy(inode.name, filename, MAX_NAME_STRLEN);

        inode.file_size = 0;

        for (int i = 0; i < MAX_FILE_SIZE; i++) {

                inode.direct_blocks[i] = -1;  /* No data blocks assigned yet */

        }

        simplefs_writeInode(inode_num, &inode);

        return inode_num;

}


void simplefs_delete(char *filename){

        /*

           Delete file with name `filename` from disk

*/
        if(filename == NULL || strlen(filename) == 0)

        {

                fprintf(stderr,"Error : Invalid filename\n");

                return;

        }

        struct inode_t inode;

        int inode_num = -1;

        /* Find the inode associated with the file */

        for (int i = 0; i < NUM_INODES; i++) {

                simplefs_readInode(i, &inode);

                if (strcmp(inode.name, filename) == 0) {

                        inode_num = i;

                        break;

                }

        }

        if (inode_num == -1) {
                fprintf(stderr,"filename not found\n");
                return ;

        }

        /* Free data blocks associated with the file */

        for (int i = 0; i < MAX_FILE_SIZE && inode.direct_blocks[i] != -1; i++) {

                simplefs_freeDataBlock(inode.direct_blocks[i]);

        }

        /* Free the inode */

        simplefs_freeInode(inode_num);

}


int simplefs_open(char *filename){

        /*

           Open file with name `filename` and return file handle

*/
        if(filename == NULL || strlen(filename) == 0)

        {

                fprintf(stderr,"Invalid file Name\n");

                return -1;

        }

        struct inode_t inode;

        int inode_num = -1;

        /* Find the inode associated with the file */

        for (int i = 0; i < NUM_INODES; i++) {

                simplefs_readInode(i, &inode);

                if (strcmp(inode.name, filename) == 0) {

                        inode_num = i;

                        break;

                }

        }

        if (inode_num == -1) {
                fprintf(stderr,"Requested filename NOT found\n");
                return -1;

        }

        /* Find an available file handle */

        for (int i = 0; i < MAX_OPEN_FILES; i++) {

                /* if file is already opened */

                if(file_handle_array[i].inode_number == inode_num)

                        return i;

                /* allocating free slot */

                if (file_handle_array[i].inode_number == -1) {

                        file_handle_array[i].inode_number = inode_num;

                        file_handle_array[i].offset = 0;

                        return i;

                }

        }

        return -1;

}

void simplefs_close(int file_handle){
    /*
	    Close file pointed by `file_handle`
	*/
    if (file_handle < 0 || file_handle >= MAX_OPEN_FILES || file_handle_array[file_handle].inode_number == -1) {
        return;
    }
    file_handle_array[file_handle].inode_number = -1;  /* Mark file handle as closed */
    file_handle_array[file_handle].offset = 0;
}



/* Function to read nbytes of data from a file into a buffer */
int simplefs_read(int file_handle, char *buf, int nbytes) {
    /*
        This function reads `nbytes` of data into `buf` from the file pointed
        by `file_handle`, starting at the current offset. It handles partial 
        block reads and fails if `nbytes` cannot be fully read.
    */

    /* Validate file handle */
    if (file_handle < 0 || file_handle >= MAX_OPEN_FILES || file_handle_array[file_handle].inode_number == -1) {
        return -1;  /* Invalid file handle */
    }

    /* Retrieve the inode and current file offset */
    struct inode_t inode;
    simplefs_readInode(file_handle_array[file_handle].inode_number, &inode);

    int offset = file_handle_array[file_handle].offset;
    int file_size = MAX_FILE_SIZE * BLOCKSIZE ;

    /* Check if the read would exceed file size */
    if (offset + nbytes > file_size) {
        return -1;  /* Reading beyond end of file */
    }

    int bytes_read = 0;  /* Total bytes read so far */
    int block_index = offset / BLOCKSIZE;  /* Start block index */
    int block_offset = offset % BLOCKSIZE; /* Offset within the block */

    /* Read data block by block */
    while (bytes_read < nbytes) {
        if (block_index >= MAX_FILE_SIZE || inode.direct_blocks[block_index] == -1) {
            return -1;  /* Invalid block reference */
        }

        char block_buf[BLOCKSIZE];
        simplefs_readDataBlock(inode.direct_blocks[block_index], block_buf);

        /* Calculate how much to read from the current block */
        int bytes_in_block = BLOCKSIZE - block_offset;
        int bytes_to_copy = (nbytes - bytes_read < bytes_in_block) ? nbytes - bytes_read : bytes_in_block;

        /* Copy data from block to buffer */
        memcpy(buf + bytes_read, block_buf + block_offset, bytes_to_copy);

        bytes_read += bytes_to_copy;
        block_index++;
        block_offset = 0;  /* Subsequent reads start at block beginning */
    }


    return 0;  /* Success */
} 



int simplefs_write(int file_handle, char *buf, int nbytes) {
    /* write `nbytes` of data from `buf` to file pointed by `file_handle` starting at current offset */
    if (file_handle < 0 || file_handle >= MAX_OPEN_FILES || file_handle_array[file_handle].inode_number == -1) {
        return -1;
    }

    struct inode_t inode;
    int bytes_written = 0;
    int offset = file_handle_array[file_handle].offset;
    
    /* Read inode associated with file */
    simplefs_readInode(file_handle_array[file_handle].inode_number, &inode);

    while (bytes_written < nbytes) {
        int block_index = offset / BLOCKSIZE;  /* Determine block index based on offset */
        int block_offset = offset % BLOCKSIZE; /* Offset within the block */

        /* Check if block is allocated, if not, allocate a new one */
        if (block_index >= MAX_FILE_SIZE) {
            return -1;
        }

        if (inode.direct_blocks[block_index] == -1) {
            int new_block = simplefs_allocDataBlock();
            if (new_block == -1) {
                return -1;
            }
            inode.direct_blocks[block_index] = new_block;  /* Link new block to inode */
	    simplefs_writeDataBlock(new_block,"");
        }
	
        int block_num = inode.direct_blocks[block_index];
        char block_buf[BLOCKSIZE];
	simplefs_readDataBlock(block_num, block_buf);

        /* Determine how much we can write in this block */
        int bytes_to_write = (nbytes - bytes_written < BLOCKSIZE - block_offset) ? 
                             nbytes - bytes_written : BLOCKSIZE - block_offset;
        memcpy(block_buf + block_offset, buf + bytes_written, bytes_to_write);


        /* Write modified block back to disk */
        simplefs_writeDataBlock(block_num, block_buf); 
        /* Update offsets and counters */
        bytes_written += bytes_to_write;
        offset += bytes_to_write;
    }

    if (inode.file_size < offset) {
        inode.file_size = offset;
    }

    /* Write the updated inode back to disk */
    simplefs_writeInode(file_handle_array[file_handle].inode_number, &inode);

    return 0;
}


int simplefs_seek(int file_handle, int nseek){
    /*
	    Increase `file_handle` offset by `nseek`
	*/
    if (file_handle < 0 || file_handle >= MAX_OPEN_FILES || file_handle_array[file_handle].inode_number == -1) {
        return -1;
    }
    
    struct inode_t inode;
    simplefs_readInode(file_handle_array[file_handle].inode_number, &inode);

    /* Check new offset within file size limits */
    int new_offset = file_handle_array[file_handle].offset + nseek ;
    
    if (new_offset < 0 || new_offset > (MAX_FILE_SIZE*BLOCKSIZE) ) {
        return -1;
    }
    
    file_handle_array[file_handle].offset = new_offset;
    return 0;
}

