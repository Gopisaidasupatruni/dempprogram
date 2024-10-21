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

for file in "$SOURCE"/*
do
#	if [ -f $file ]
#	then
#	echo $file
#	fi
	filename=${file##*/}
#echo $filename
new_filename=$(echo "$filename" | sed 's/\(.\)\(.*\)/\U\1\L\2/')
echo $new_filename

# Copy the file to dest directory
cp "$file" "$DEST/$new_filename"

sudo chown "$OWNER" "$DEST/$new_filename"

sudo chmod "$FILE" "$DEST/$new_filename"

done
#end
