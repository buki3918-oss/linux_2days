#!/bin/bash

if [ -d "$1" ]; then
    echo "Directory exists: $1"
else
    echo "Directory not found: $1"
fi
