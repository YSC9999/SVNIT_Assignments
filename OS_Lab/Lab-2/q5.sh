#!/bin/bash

# 5. Write a Shell Script for counting the lines in the text file.

# Check if a filename is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 filename"
    echo "Please provide a filename to count lines."
    exit 1
fi

FILENAME=$1

if [ -f "$FILENAME" ]; then
    LINES=$(wc -l < "$FILENAME")
    echo "The file '$FILENAME' has $LINES lines."
else
    echo "Error: File '$FILENAME' does not exist."
fi
