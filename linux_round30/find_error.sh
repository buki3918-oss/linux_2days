#!/bin/bash

echo "=== Search ERROR in log files ==="

for f in *.log; do
    echo "Checking $f"
    grep "ERROR" "$f"
done
