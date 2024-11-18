/* REQUIRED HEADER FILES */
#include "simplefs-disk.h"
#include <string.h>
#include <assert.h>


/* Declare the external file handle array */
extern struct filehandle_t file_handle_array[MAX_OPEN_FILES];

/* simplefscreate: Create a file and allocate its inode */
int simplefs_create(char *filename) {

	/* Allocating a free inode */
    int inodenum = simplefs_allocInode();
    if (inodenum == -1)
	    return -1;
/* Mark inode as used in the freelist */
    inode_freelist[inodenum] = 1;
    struct inode_t inode;

	int iFound = 0;
	for(int i= 0; i< MAX_FILES; i++)
	{
		simplefs_readInode(i,&inode);
		if(strcmp(inode.name,filename)==0)
		{
			iFound = 1;
		}
	}
	if(iFound == 1)
	{
		fprintf(stderr,"Filename already exist\n");
		return -1;
	}


    /* Clear the inode structure */
    memset(&inode, 0, sizeof(struct inode_t));

  strncpy(inode.name, filename, MAX_NAME_STRLEN);
   /* Set inode status and initialize other fields */
    inode.status = INODE_IN_USE;
    inode.file_size = 0;
    for (int i = 0; i < MAX_FILE_SIZE; i++) inode.direct_blocks[i] = -1;

    simplefs_writeInode(inodenum, &inode);
    return inodenum;
}

/* simplefs_open: Open a file and return its file descriptor */
int simplefs_open(char *filename) {
    struct inode_t inode;
    /* Search for the file in the inode table */
    for (int i = 0; i < NUM_INODES; i++) {
        simplefs_readInode(i, &inode);
	/* Check if the inode is in use and matches the given filename */
        if (inode.status == INODE_IN_USE && strcmp(inode.name, filename) == 0) {
            for (int j = 0; j < MAX_OPEN_FILES; j++) {
                if (file_handle_array[j].inode_number == -1) {
                    file_handle_array[j].inode_number = i;
		    /* Initialize file offset */
                    file_handle_array[j].offset = 0;
                    return j;
                }
            }
        }
    }
    return -1;  /* File not found or no free file descriptors */
}
/* simplefs_delete: Function to delete a file by freeing its inode and data blocks */
int simplefs_delete(char *filename) {
	/* Temporary structure to hold inode data */
    struct inode_t inode;
    /* Variable to store the inode number */
    int inodenum = -1;
    
    /*  Search for the inode by filename */
    for (int i = 0; i < NUM_INODES; i++) {
        simplefs_readInode(i, &inode);
        if (inode.status == INODE_IN_USE && strcmp(inode.name, filename) == 0) {
            inodenum = i;
            break;
        }
    }
     /* If no matching file is found */
    if (inodenum == -1) {
        fprintf(stderr, "File not found: %s\n", filename);
        return -1;  // File not found
    }

    // Free all data blocks
    for (int i = 0; i < MAX_FILE_SIZE; i++) {
        if (inode.direct_blocks[i] != -1) {
		/* Release the block */
            simplefs_freeDataBlock(inode.direct_blocks[i]);
	    /* Mark the block as unallocated */
            inode.direct_blocks[i] = -1;
        }
    }

    // Free the inode
    //inode.status = INODE_FREE;
    /*  Update the inode freelist */
//    inode_freelist[inodenum] = 0;  // Mark as free
  //  simplefs_writeInode(inodenum, &inode);
	simplefs_freeInode(inodenum);

    inode.status = INODE_FREE;
    inode.file_size = 0;
    for (int i = 0; i < MAX_FILE_SIZE; i++) {
        inode.direct_blocks[i] = -1;
    }
    simplefs_writeInode(inodenum, &inode);


    
    return 0;  
}


