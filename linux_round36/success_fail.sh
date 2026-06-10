#!/bin/bash

echo "Test 1: list current directory"
ls
echo "Exit status: $?"

echo "-------------------------"

echo "Test 2: list missing file"
ls missing.txt
echo "Exit status: $?"
