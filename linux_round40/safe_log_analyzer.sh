#!/bin/bash
set -euo pipefail

LOG_DIR="logs"
REPORT_FILE="log_report.txt"

cleanup() {
    rm -f .tmp_log_count
}

error_handler() {
    echo "Error occurred at line: $1"
}

trap cleanup EXIT
trap 'error_handler $LINENO' ERR

check_log_dir() {
    if [ ! -d "$LOG_DIR" ]; then
        echo "Error: log directory not found: $LOG_DIR"
        exit 1
    fi
}

show_menu() {
    echo "================================"
    echo " Safe Log Analyzer"
    echo "================================"
    echo "1) Show log files"
    echo "2) Search ERROR"
    echo "3) Search WARNING"
    echo "4) Count log lines"
    echo "5) Generate report"
    echo "q) Quit"
    echo "Please choose an option:"
}

show_log_files() {
    check_log_dir

    echo "=== Log Files ==="
    ls -l "$LOG_DIR"
}

search_error() {
    check_log_dir

    echo "=== Search ERROR ==="

    for file in "$LOG_DIR"/*.log; do
        echo "File: $file"

        if grep -q "ERROR" "$file"; then
            grep "ERROR" "$file"
        else
            echo "No ERROR found."
        fi

        echo "---"
    done
}

search_warning() {
    check_log_dir

    echo "=== Search WARNING ==="

    for file in "$LOG_DIR"/*.log; do
        echo "File: $file"

        if grep -q "WARNING" "$file"; then
            grep "WARNING" "$file"
        else
            echo "No WARNING found."
        fi

        echo "---"
    done
}

count_log_lines() {
    check_log_dir

    echo "=== Count Log Lines ==="

    total=0

    for file in "$LOG_DIR"/*.log; do
        lines=$(wc -l < "$file")
        echo "$file: $lines lines"
        total=$(( total + lines ))
    done

    echo "Total lines: $total"
}

generate_report() {
    check_log_dir

    echo "Generating report: $REPORT_FILE"

    {
        echo "Safe Log Analyzer Report"
        echo "========================"
        echo "Generated at: $(date)"
        echo ""
        echo "Log files:"
        ls -l "$LOG_DIR"
        echo ""
        echo "Line count:"
        for file in "$LOG_DIR"/*.log; do
            lines=$(wc -l < "$file")
            echo "$file: $lines lines"
        done
        echo ""
        echo "ERROR summary:"
        grep -h "ERROR" "$LOG_DIR"/*.log || true
        echo ""
        echo "WARNING summary:"
        grep -h "WARNING" "$LOG_DIR"/*.log || true
    } > "$REPORT_FILE"

    echo "Report generated successfully."
}

main() {
    check_log_dir

    while true; do
        show_menu
        read choice

        case "$choice" in
            1)
                show_log_files
                ;;
            2)
                search_error
                ;;
            3)
                search_warning
                ;;
            4)
                count_log_lines
                ;;
            5)
                generate_report
                ;;
            q)
                echo "Goodbye!"
                exit 0
                ;;
            *)
                echo "Unknown option: $choice"
                ;;
        esac

        echo ""
    done
}

main
