#!/bin/bash

. ./config.cfg

log_message() {
  if [ "$SOURCE" = "true" ]; then
    echo "$1" >> /tmp/script_log.txt
  fi
}

echo "Enter the filename:"
read filename
log_message "User entered filename: $filename"

if [ ! -e "$filename" ]; then
  echo "File does not exist."
  exit 1
fi

# Check if the current user owns the file
if [ ! -O "$filename" ]; then
  echo "You do not own the file."
  exit 1
fi

# Check if the file is writable
if [ ! -w "$filename" ]; then
  echo "File is not writable. Making it writable..."
  log_message "File is not writable. Attempting to make it writable."
  chmod u+w "$filename"
  if [ $? -eq 0 ]; then
    echo "File is now writable."
    log_message "File permissions successfully changed to writable."
  else
    echo "Failed to change file permissions."
    log_message "Failed to change file permissions."
    exit 1
  fi
else
  echo "File is already writable."
  log_message "File is already writable."
fi

