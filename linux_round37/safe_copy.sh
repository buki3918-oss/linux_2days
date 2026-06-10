#!/bin/bash

if [ $# -lt 2 ]; then
    echo "Error: missing arguments."
    echo "Usage: ./safe_copy.sh <source> <target>"
    exit 1
fi

source="$1"
target="$2"

if [ ! -f "$source" ]; then
    echo "Error: source file not found: $source"
    exit 1
fi

cp "$source" "$target"

if [ $? -eq 0 ]; then
    echo "Copy success: $source -> $target"
    exit 0
else
    echo "Copy failed."
    exit 1
fi
