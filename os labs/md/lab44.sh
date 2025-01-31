#!/bin/bash

# Check if at least one option and a file are passed
if [ "$#" -lt 2 ]; then
    echo "Usage: $0 <option> <file>"
    echo "Options:"
    echo "  -linecount    Count lines in the file"
    echo "  -wordcount    Count words in the file"
    echo "  -charcount    Count characters in the file"
    exit 1
fi

# Get the option and the input file
option="$1"
file="$2"

# Check if the file exists
if [ ! -f "$file" ]; then
    echo "Error: File '$file' not found."
    exit 2
fi

# Perform action based on the option
case "$option" in
    -linecount)
        # Count lines in the file
        line_count=$(wc -l < "$file")
        echo "Number of lines: $line_count"
        ;;
    -wordcount)
        # Count words in the file
        word_count=$(wc -w < "$file")
        echo "Number of words: $word_count"
        ;;
    -charcount)
        # Count characters in the file
        char_count=$(wc -m < "$file")
        echo "Number of characters: $char_count"
        ;;
    *)
        # Invalid option
        echo "Invalid option: $option"
        echo "Usage: $0 <option> <file>"
        echo "Options:"
        echo "  -linecount    Count lines in the file"
        echo "  -wordcount    Count words in the file"
        echo "  -charcount    Count characters in the file"
        exit 3
        ;;
esac
