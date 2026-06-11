#!/bin/bash
set -euo pipefail

cleanup() {
    echo "Cleaning up temporary files..."
    rm -f temp.txt
}

error_handler() {
    echo "Error occurred!"
    echo "Failed at line: $1"
}

trap cleanup EXIT
trap 'error_handler $LINENO' ERR

echo "Step 1: create temp file"
echo "temporary data" > temp.txt
ls -l temp.txt

echo "Step 2: process file"
cat temp.txt

echo "Step 3: trigger error"
grep "ERROR" missing.log

echo "This line will not run"
