#!/bin/bash

if [ $# -lt 2 ]; then
    echo "Error: missing arguments."
    echo "Usage: ./safe_grep.sh <keyword> <filename>"
    exit 1
fi

keyword="$1"
filename="$2"

if [ ! -f "$filename" ]; then
    echo "Error: file not found: $filename"
    exit 1
fi

if grep -q "$keyword" "$filename"; then
    echo "Keyword found: $keyword"
    grep "$keyword" "$filename"
    exit 0
else
    echo "Keyword not found: $keyword"
    exit 1
fi
