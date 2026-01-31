
FILE="Assignment1/notes.txt"

if [ -f "$FILE" ]; then
    echo "Content of $FILE:"
    cat "$FILE"
    echo ""
    echo "Counts (Lines Words Characters Filename):"
    wc "$FILE"
else
    echo "File $FILE does not exist. Please run q1.sh first."
fi
