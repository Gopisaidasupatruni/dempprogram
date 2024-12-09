/* REQUIRED HEADER FILES */
#include "simplefs-disk.h"
#include <string.h>
#include <assert.h>
/* Example initialization of inode freelist */
int inode_freelist[NUM_INODES] = {0};  // 0 means free, 1 means in use

/* Declare the external file handle array */
extern struct filehandle_t file_handle_array[MAX_OPEN_FILES];

/* simplefscreate: Create a file and allocate its inode */
int simplefs_create(char *filename) {
	if(strlen(filename)==0)
	{
		printf("enter filename correctly\n");
		return 1;
	}

	/* Allocating a free inode */
    int inodenum = simplefs_allocInode();
    if (inodenum == -1) return -1;
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
    
    // Search for the inode by filename
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

int simplefs_read(int file_handle, char *buf, int nbytes) {
    /* Check if the provided file handle is valid */
  if (file_handle < 0 || file_handle >= MAX_OPEN_FILES) {
        fprintf(stderr, "Error: Invalid file handle.\n");
        return -1;
    }

    /* Retrieve the inode number and current offset for the file */
    int inodenum = file_handle_array[file_handle].inode_number;
    int offset = file_handle_array[file_handle].offset;

    struct inode_t inode;
    simplefs_readInode(inodenum, &inode);

    // Ensure read does not exceed file size
    if (offset + nbytes > inode.file_size) {
        fprintf(stderr, "Error: Read exceeds file size.\n");
        return -1;
    }

    int remaining = nbytes;         // Remaining bytes to read
    int buffer_pos = 0;             // Position in the buffer
    int current_block = offset / BLOCKSIZE;
    int block_offset = offset % BLOCKSIZE;

    /* Read data in a loop until all requested bytes are read */
    while (remaining > 0) {
        int bytes_to_read = BLOCKSIZE - block_offset;
        if (remaining < bytes_to_read) {
            bytes_to_read = remaining;
        }

        char block_data[BLOCKSIZE];
        simplefs_readDataBlock(inode.direct_blocks[current_block], block_data);

        memcpy(buf + buffer_pos, block_data + block_offset, bytes_to_read);

        buffer_pos += bytes_to_read;
        remaining -= bytes_to_read;
        current_block++;
        block_offset = 0;
    }

    return 0;
}
int simplefs_write(int file_handle, char *buf, int nbytes) {
    
    if (file_handle < 0 || file_handle >= MAX_OPEN_FILES) {
        fprintf(stderr, "Error: Invalid file handle.\n");
        return -1; 
    }

    /* Retrieve inode number and current offset for the file */
    int inodenum = file_handle_array[file_handle].inode_number;
    int offset = file_handle_array[file_handle].offset;


    
    struct inode_t *inode = (struct inode_t *)malloc(sizeof(struct inode_t));
    simplefs_readInode(inodenum, inode);

    
    int buffer_offset = 0;            // Offset in the input buffer
    int current_block = offset / BLOCKSIZE; // Determine the starting block
    int block_offset = offset % BLOCKSIZE;  // Offset within the starting block
    int bytesend = BLOCKSIZE - block_offset; // Bytes from offset to end of the block
    int bytes_to_write;               // Number of bytes to write in the current iteration
    char temp_block[BLOCKSIZE];       // Temporary buffer for a data block

    /* Adjust file size to reflect the current offset */
    if (inode->file_size < offset) {
        inode->file_size = offset;
    }

    /* Write data to the file */
    while (nbytes > 0) {
        /* Determine the number of bytes to write in this iteration */
       if (nbytes < bytesend) {
            bytes_to_write = nbytes;
        } else {
            bytes_to_write = bytesend;
        }

        
        if (inode->direct_blocks[current_block] == -1) {
            int new_block = simplefs_allocDataBlock();
            if (new_block == -1) {
                fprintf(stderr, "Error: Insufficient blocks available.\n");
                free(inode);
                return -1;
            }
            inode->direct_blocks[current_block] = new_block;
        }

        /* Read the block if it exists, then update its contents */
      simplefs_readDataBlock(inode->direct_blocks[current_block], temp_block);
        memcpy(temp_block + block_offset, buf + buffer_offset, bytes_to_write);
        simplefs_writeDataBlock(inode->direct_blocks[current_block], temp_block);

        /* Update variables for the next iteration */
        buffer_offset += bytes_to_write;
        nbytes -= bytes_to_write;
        inode->file_size += bytes_to_write;
        current_block++;
        block_offset = 0; 
        bytesend = BLOCKSIZE;
    }

    /* Write the updated inode back to disk */
    simplefs_writeInode(inodenum, inode);

    free(inode);
   return 0;
}

/*simplefs_seek: To change offset by a specified value */
int simplefs_seek(int file_handle, int nseek) {
	/*  Validate file handle */
    if (file_handle < 0 || file_handle >= MAX_OPEN_FILES) {
        fprintf(stderr, "Invalid file handle\n");
        return -1;
    }
    /* Getting inodenumber and offset */
    int inodenum = file_handle_array[file_handle].inode_number;
    int offset = file_handle_array[file_handle].offset;

    /* Read the inode to get the file size */
    struct inode_t* inodeptr = (struct inode_t*)malloc(sizeof(struct inode_t));
    simplefs_readInode(inodenum, inodeptr);

    /* calculate new offset */
    int new_offset = offset + nseek;
    
    /* Ensure the offset doesn't go beyond the file's size */
    if (new_offset < 0) {
        /* Offset cannot be negative, set it to 0 */
        file_handle_array[file_handle].offset = 0;
    } else if (new_offset > inodeptr->file_size) {
        /* Offset cannot exceed file size, set it to the end of the file */
        file_handle_array[file_handle].offset = inodeptr->file_size;
    } else {
        /* Set the offset to the new value */
        file_handle_array[file_handle].offset = new_offset;
    }

    free(inodeptr);
    return 0;
}

/* simplefs_close: Close a file */
void simplefs_close(int file_handle) {
	/* mark the file as closed */
    file_handle_array[file_handle].inode_number = -1;
    /* resetting offset */
    file_handle_array[file_handle].offset = 0;
}

