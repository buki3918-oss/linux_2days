#!/bin/bash

while read line; do
    echo "Student: $line"
done < students.txt
