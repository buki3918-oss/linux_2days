#!/bin/bash

echo "=== List all txt files ==="

for f in *.txt; do
    echo "File: $f"
    cat "$f"
    echo "---"
done
