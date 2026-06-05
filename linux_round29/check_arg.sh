#!/bin/bash

if [ -z "$1" ]; then
    echo "No argument provided."
    echo "Usage: ./check_arg.sh filename"
else
    echo "Argument received: $1"
fi
