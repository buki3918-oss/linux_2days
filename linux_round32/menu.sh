#!/bin/bash

while true; do
    echo "=========================="
    echo " Linux Practice Menu"
    echo "=========================="
    echo "1) Show date"
    echo "2) Show current path"
    echo "3) Show current user"
    echo "4) List files"
    echo "q) Quit"
    echo "Please choose an option:"
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
        4)
            ls -l
            ;;
        q)
            echo "Goodbye!"
            break
            ;;
        *)
            echo "Unknown option: $choice"
            ;;
    esac

    echo ""
done
