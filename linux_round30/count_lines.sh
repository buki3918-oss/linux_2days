#!/bin/bash

echo "=== Count lines in txt files ==="

for f in *.txt; do
    echo "$f:"
    wc -l "$f"
done
