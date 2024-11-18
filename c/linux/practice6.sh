#!/bin/bash

read -p "Enter the filename: " filename

if [ ! -e "$filename" ]; then
  echo "File does not exist."
  exit 1
fi

if [ ! -O "$filename" ]; then
  echo "You do not own this file."
  exit 1
fi

# Check if the file is writable
if [ -w "$filename" ]; then
  echo "The file is writable."

else
	echo "not writable"
	chmod +w "$filename"
fi
