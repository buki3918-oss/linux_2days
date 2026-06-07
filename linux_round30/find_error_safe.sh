#!/bin/bash

echo "=== Search ERROR in log files ==="

for f in *.log; do
    echo "Checking $f"

    if grep -q "ERROR" "$f"; then
        echo "ERROR found in $f"
        grep "ERROR" "$f"
    else
        echo "No ERROR in $f"
    fi

    echo "---"
done
