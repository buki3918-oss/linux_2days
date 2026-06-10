#!/bin/bash

check_file() {
    if [ -f "$1" ]; then
        echo "File exists: $1"
        return 0
    else
        echo "File not found: $1"
        return 1
    fi
}

touch test.txt

check_file test.txt
echo "Function return code: $?"

echo "-------------------------"

check_file missing.txt
echo "Function return code: $?"
