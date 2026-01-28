#!/bin/bash

# 3. Create a directory named ProjectWorkspace. Inside ProjectWorkspace, create subdirectories Docs, Code, and Resources.
# In the Docs directory, create an empty file named README.txt. 
# Move into the Code directory and create an empty file main.py. 
# List all files and directories in ProjectWorkspace to verify the setup.

echo "Creating directory structure..."
mkdir -p ProjectWorkspace/Docs
mkdir -p ProjectWorkspace/Code
mkdir -p ProjectWorkspace/Resources

echo "Creating README.txt in Docs..."
touch ProjectWorkspace/Docs/README.txt

echo "Moving into Code directory and creating main.py..."
cd ProjectWorkspace/Code
touch main.py
cd ../.. # navigate back to original directory

echo ""
echo "Verifying setup (Listing files in ProjectWorkspace):"
ls -R ProjectWorkspace
