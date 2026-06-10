#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Error: missing filename."
    echo "Usage: ./check_arg.sh <filename>"
    exit 1
fi

echo "You entered: $1"
exit 0
