#Author: Gopisai
#Date  : 21/10/2024
#!/bin/bash

#checking arguments
if [ $# -ne 4 ]
then
	echo provide dir1 dir2 owner permissions
	exit 1
fi

#Assigning arguments
SOURCE=$1
DEST=$2
OWNER=$3
FILE=$4

#checking source directory one exists or not
if [ -d dir1 ]
then echo dir1 exists to copy files to dir2!
else echo dir1 not found!
fi

#checking destination directory
if [ -d dir2 ]
then echo dir2 exists!
else echo dir2 not found!
fi

#for loop to traverse all files in source directory
for file in "$SOURCE"/*
do

	filename=${file##*/}

	echo dir1 $filename
        #To change first letter of filename into capital and remaining into small
	new_filename=$(echo "$filename" | sed 's/\(.\)\(.*\)/\U\1\L\2/')
	echo dir2 $new_filename 

# Copy the file to dest directory
cp "$file" "$DEST/$new_filename"

#To change the user ownership of file
sudo chown "$OWNER" "$DEST/$new_filename"

#To change the permissions of file
sudo chmod "$FILE" "$DEST/$new_filename"

done
#end
