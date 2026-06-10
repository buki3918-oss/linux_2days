#!/bin/bash

show_menu() {
    echo "=============================="
    echo " Linux Toolkit Function Menu"
    echo "=============================="
    echo "1) Show system info"
    echo "2) Check file exists"
    echo "3) Search ERROR in log files"
    echo "4) Count txt files"
    echo "q) Quit"
    echo "Please choose an option:"
}

show_system_info() {
    echo "=== System Info ==="
    echo "User: $(whoami)"
    echo "Path: $(pwd)"
    echo "Date: $(date)"
}

check_file_exists() {
    echo "Enter filename:"
    read filename

    if [ -f "$filename" ]; then
        echo "File exists: $filename"
    else
        echo "File not found: $filename"
    fi
}

search_error_logs() {
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
}

count_txt_files() {
    echo "=== Count txt files ==="

    for f in *.txt; do
        echo "$f:"
        wc -l "$f"
    done
}

while true; do
    show_menu
    read choice

    case "$choice" in
        1)
            show_system_info
            ;;

        2)
            check_file_exists
            ;;

        3)
            search_error_logs
            ;;

        4)
            count_txt_files
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
