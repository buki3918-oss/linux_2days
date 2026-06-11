#!/bin/bash
set -e

cleanup() {
    echo "Cleaning up..."
    rm -f temp.txt
}

trap cleanup EXIT

echo "Create temp file"
echo "temporary data" > temp.txt

echo "Temp file created:"
ls -l temp.txt

echo "Now trigger an error"
ls missing.txt

echo "This line will not run"
