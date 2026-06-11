#!/bin/bash

echo "Test pipeline without pipefail"

grep "ERROR" missing.log | wc -l

echo "Exit status: $?"
echo "Script continues."
