#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Error: missing filename."
    echo "Usage: ./safe_cat.sh <filename>"
    exit 1
fi

filename="$1"

if [ ! -f "$filename" ]; then
    echo "Error: file not found: $filename"
    exit 1
fi

echo "=== File Content: $filename ==="
cat "$filename"

exit 0
