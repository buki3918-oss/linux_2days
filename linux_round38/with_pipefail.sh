#!/bin/bash
set -o pipefail

echo "Test pipeline with pipefail"

grep "ERROR" missing.log | wc -l

echo "Exit status: $?"
echo "Script continues."
