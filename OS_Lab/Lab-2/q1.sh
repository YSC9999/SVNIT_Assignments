#!/bin/bash

# 1. Write a program to create an empty file named notes.txt inside the Assignment1 directory.
# Add the text "UNIX is fun!" to the file notes.txt using a single command.

# Create Assignment1 directory if it doesn't exist
mkdir -p Assignment1

# Create an empty file named notes.txt
touch Assignment1/notes.txt

# Add text to the file using a single command (redirection)
echo "UNIX is fun!" > Assignment1/notes.txt

echo "Task 1 Completed: created Assignment1/notes.txt with content."
