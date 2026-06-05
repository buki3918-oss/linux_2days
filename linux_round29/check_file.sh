#!/bin/bash

if [ -f "$1" ]; then
    echo "File exists: $1"
else
    echo "File not found: $1"
fi
