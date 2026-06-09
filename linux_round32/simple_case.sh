#!/bin/bash

echo "Choose an option:"
echo "1) Show date"
echo "2) Show current path"
echo "3) Show current user"
echo "q) Quit"

read choice

case "$choice" in
    1)
        date
        ;;
    2)
        pwd
        ;;
    3)
        whoami
        ;;
    q)
        echo "Goodbye!"
        ;;
    *)
        echo "Unknown option: $choice"
        ;;
esac
