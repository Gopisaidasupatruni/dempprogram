#!/bin/bash

read -p "Enter the filename: " file

if [ ! -e "$file" ]; then
  echo "File does not exist."
  exit 1
fi

if [ ! -O "$file" ]; then
  echo "You do not own this file."
  exit 1
fi

# Check if the file is writable
if [ -w "$file" ]; then
  echo "The file is writable."

else
        echo "not writable"
        chmod +w "$file"
fi
