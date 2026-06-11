#!/bin/bash
set -e

error_handler() {
    echo "Error occurred!"
    echo "Script failed at line: $1"
}

trap 'error_handler $LINENO' ERR

echo "Step 1: start"

ls missing.txt

echo "Step 2: this line will not run"
