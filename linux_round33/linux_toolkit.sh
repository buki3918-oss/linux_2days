#!/bin/bash

while true; do
    echo "=============================="
    echo " Linux Toolkit Menu"
    echo "=============================="
    echo "1) Show system info"
    echo "2) Check file exists"
    echo "3) Search ERROR in log files"
    echo "4) Count txt files"
    echo "q) Quit"
    echo "Please choose an option:"
    read choice

    case "$choice" in
        1)
            echo "=== System Info ==="
            echo "User: $(whoami)"
            echo "Path: $(pwd)"
            echo "Date: $(date)"
            ;;

        2)
            echo "Enter filename:"
            read filename

            if [ -f "$filename" ]; then
                echo "File exists: $filename"
            else
                echo "File not found: $filename"
            fi
            ;;

        3)
            echo "=== Search ERROR in log files ==="

            for f in *.log; do
                echo "Checking $f"

                if grep -q "ERROR" "$f"; then
                    echo "ERROR found in $f"
                    grep "ERROR" "$f"
                else
                    echo "No ERROR in $f"
                fi

                echo "---"
            done
            ;;

        4)
            echo "=== Count txt files ==="

            for f in *.txt; do
                echo "$f:"
                wc -l "$f"
            done
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
