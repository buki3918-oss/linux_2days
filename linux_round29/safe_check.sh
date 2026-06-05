#!/bin/bash

if [ -z "$1" ]; then
    echo "Error: no filename provided."
    echo "Usage: ./safe_check.sh filename"
elif [ -f "$1" ]; then
    echo "File exists: $1"
else
    echo "File not found: $1"
fi
