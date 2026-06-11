#!/bin/bash
set -euo pipefail

temp_file=$(mktemp)

cleanup() {
    echo "Cleaning up: $temp_file"
    rm -f "$temp_file"
}

trap cleanup EXIT

echo "Temp file is: $temp_file"

echo "temporary data" > "$temp_file"

echo "File content:"
cat "$temp_file"

echo "Trigger error"
ls missing.txt

echo "This line will not run"
