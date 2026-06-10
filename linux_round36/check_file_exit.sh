#!/bin/bash

if [ -f "$1" ]; then
    echo "File exists: $1"
    exit 0
else
    echo "File not found: $1"
    exit 1
fi
