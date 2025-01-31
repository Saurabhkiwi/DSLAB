#!/bin/bash

# Find all .txt files in the current directory and its subdirectories
find . -type f -name "*.txt" | while read -r file; do
    # Construct the new file name by replacing .txt with .text
    new_file="${file%.txt}.text"
    
    # Rename the file
    mv "$file" "$new_file"
    
    # Optional: Print the renaming action
    echo "Renamed: $file to $new_file"
done
