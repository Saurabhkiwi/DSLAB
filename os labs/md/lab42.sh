#!/bin/bash

# Check if any files are passed as arguments
if [ "$#" -eq 0 ]; then
    echo "Usage: $0 <file1> <file2> ... <fileN>"
    exit 1
fi

# Loop through all the arguments (files)
for file in "$@"; do
    # Check if the file exists
    if [ -e "$file" ]; then
        # Ask for confirmation before deleting
        read -p "Are you sure you want to delete '$file'? (y/n): " confirm
        if [[ "$confirm" =~ ^[Yy]$ ]]; then
            rm "$file" && echo "'$file' has been deleted."
        else
            echo "'$file' was not deleted."
        fi
    else
        echo "File '$file' does not exist."
    fi
done
