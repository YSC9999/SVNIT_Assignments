#!/bin/bash
# Script to rename .jpg files to start with today's date (YYYY-MM-DD)
date_prefix=$(date +%F)
for file in *.jpg; do
  if [ -f "$file" ]; then
    mv "$file" "$date_prefix-$file"
  fi
done
echo "Renaming complete."