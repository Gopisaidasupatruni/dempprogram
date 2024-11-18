#!/bin/bash

# Checking if exactly 4 arguments are provided
if [ $# -ne 4 ]
then
        echo "Provide dir1, dir2, owner, and permissions"
        exit 1
fi

# Assigning arguments
SOURCE=$1
DEST=$2
OWNER=$3
PERMISSIONS=$4

# Checking if source directory exists
if [ -d "$SOURCE" ]
then
        echo "$SOURCE exists, ready to copy files to $DEST!"
else
        echo "$SOURCE not found!"
        exit 1
fi

# Checking if destination directory exists
if [ -d "$DEST" ]
then
        echo "$DEST exists!"
else
        echo "$DEST not found!"
        exit 1
fi

# Checking if there are any regular files in the source directory using -f
found_files=false
for file in "$SOURCE"/*
do
    if [ -f "$file" ]
    then
        found_files=true
        break
    fi
done

if ! $found_files
then
    echo "No files are in $SOURCE"
    exit 1
fi

# For loop to traverse all files in the source directory
for file in "$SOURCE"/*
do
    if [ -f "$file" ] # Ensure it's a regular file
    then
        # Getting the basename of the file (filename without path)
        filename=$(basename "$file")

        # Extract the first character and make it uppercase using cut and tr (^ equivalent)
        first_char_upper=$(echo "$filename" | cut -c1 | tr '[:lower:]' '[:upper:]')

        # Get the rest of the filename starting from the second character (-c2- equivalent)
        rest_of_filename=$(echo "$filename" | cut -c2- | tr '[:upper:]' '[:lower:]')

        # Concatenate them into a new filename
        new_filename="$first_char_upper$rest_of_filename"

        # Printing the new filename for verification
        echo "New filename: $new_filename"

        # Copying the file to the destination with the new filename
        cp "$file" "$DEST/$new_filename"

        # Changing ownership and permissions
        chown "$OWNER" "$DEST/$new_filename"
        chmod "$PERMISSIONS" "$DEST/$new_filename"
    fi
done

echo "File processing complete."

