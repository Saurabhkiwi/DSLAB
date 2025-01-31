#!/bin/bash

# User-defined sort function
sort_strings() {
    # Bubble sort algorithm for sorting strings
    local arr=("$@")
    local len=${#arr[@]}
    
    for ((i = 0; i < len; i++)); do
        for ((j = 0; j < len - i - 1; j++)); do
            if [[ "${arr[j]}" > "${arr[j+1]}" ]]; then
                # Swap the strings
                temp="${arr[j]}"
                arr[j]="${arr[j+1]}"
                arr[j+1]="$temp"
            fi
        done
    done
    
    # Output the sorted strings
    echo "${arr[@]}"
}

# Check if at least one argument is passed
if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <string1> <string2> ... <stringN>"
    exit 1
fi

# Call the sort function with the command line arguments
sorted_strings=$(sort_strings "$@")

# Output the sorted strings
echo "$sorted_strings"
