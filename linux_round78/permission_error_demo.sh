#!/bin/bash

echo "Permission Error Demo"
echo "====================="

echo "secret data" > demo_secret.txt
chmod 000 demo_secret.txt

echo
echo "File permission:"
ls -l demo_secret.txt

echo
echo "Trying to read demo_secret.txt:"
cat demo_secret.txt

echo
echo "Restoring permission..."
chmod 644 demo_secret.txt

echo
echo "File permission after restore:"
ls -l demo_secret.txt
