#!/bin/bash
set -euo pipefail

echo "Strict mode demo"

echo "Step 1: create app.log"
echo "INFO: started" > app.log
echo "ERROR: disk full" >> app.log
echo "INFO: finished" >> app.log

echo "Step 2: search ERROR"
grep "ERROR" app.log | wc -l

echo "Step 3: search missing file"
grep "ERROR" missing.log | wc -l

echo "This line will not run."
