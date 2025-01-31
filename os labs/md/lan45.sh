#!/bin/bash

# Function to search for patterns in the file and display matching lines
search_patterns() {
    local file="$1"
    shift
    local patterns=("$@")
    
    for pattern in "${patterns[@]}"; do
        echo "Searching for pattern: '$pattern'"
        grep -- "$pattern" "$file" && echo "Found matching lines for '$pattern'." || echo "No matches found for '$pattern'."
        echo "-----------------------------------------"
    done
}

# Function to delete all occurrences of patterns in the file
delete_patterns() {
    local file="$1"
    shift
    local patterns=("$@")
    
    for pattern in "${patterns[@]}"; do
        echo "Deleting all occurrences of pattern: '$pattern'"
        sed -i "s/$pattern//g" "$file"
        echo "Occurrences of '$pattern' have been deleted."
        echo "-----------------------------------------"
    done
}

# Function to display menu and prompt for user input
display_menu() {
    echo "Menu:"
    echo "1. Search for patterns in the file"
    echo "2. Delete all occurrences of patterns from the file"
    echo "3. Exit"
    read -p "Please choose an option (1/2/3): " choice
    echo ""
}

# Check if a file and at least one pattern are passed as command-line arguments
if [ "$#" -lt 2 ]; then
    echo "Usage: $0 <file> <pattern1> [<pattern2> ... <patternN>]"
    exit 1
fi

# The first argument is the file
file="$1"
shift
patterns=("$@")

# Check if the file exists
if [ ! -f "$file" ]; then
    echo "Error: File '$file' not found."
    exit 2
fi

# Main loop for the menu-driven script
while true; do
    display_menu
    case "$choice" in
        1)
            search_patterns "$file" "${patterns[@]}"
            ;;
        2)
            delete_patterns "$file" "${patterns[@]}"
            ;;
        3)
            echo "Exiting script."
            exit 0
            ;;
        *)
            echo "Invalid option. Please try again."
            ;;
    esac
done
