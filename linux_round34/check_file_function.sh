#!/bin/bash

check_file() {
    if [ -f "$1" ]; then
        echo "File exists: $1"
    else
        echo "File not found: $1"
    fi
}

touch test.txt

check_file "test.txt"
check_file "missing.txt"
