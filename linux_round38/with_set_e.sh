#!/bin/bash
set -e

echo "Step 1: before error"

ls missing.txt

echo "Step 2: after error"
echo "This line will not run."
