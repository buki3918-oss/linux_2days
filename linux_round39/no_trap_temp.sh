#!/bin/bash
set -e

echo "Create temp file"
echo "temporary data" > temp.txt

echo "Temp file created:"
ls -l temp.txt

echo "Now trigger an error"
ls missing.txt

echo "This line will not run"
rm temp.txt
