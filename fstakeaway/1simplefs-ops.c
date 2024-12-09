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


