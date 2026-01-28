#!/bin/bash

# 4. In the current directory, create files old_report1.txt, old_report2.txt, and current_report.txt.
# Move all files starting with "old_" into a directory named OldReports.
# Verify the moved files by listing the content of OldReports.

echo "Creating files..."
touch old_report1.txt old_report2.txt current_report.txt

echo "Creating OldReports directory..."
mkdir -p OldReports

echo "Moving old_ files to OldReports..."
# Using a glob pattern to move files starting with "old_"
mv old_* OldReports/

echo ""
echo "Verifying content of OldReports:"
ls OldReports
