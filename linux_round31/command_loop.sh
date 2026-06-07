#!/bin/bash

while true; do
    echo "Enter a command: date, pwd, whoami, or q to quit"
    read cmd

    if [ "$cmd" = "date" ]; then
        date
    elif [ "$cmd" = "pwd" ]; then
        pwd
    elif [ "$cmd" = "whoami" ]; then
        whoami
    elif [ "$cmd" = "q" ]; then
        echo "Goodbye!"
        break
    else
        echo "Unknown command: $cmd"
    fi

    echo "---"
done
