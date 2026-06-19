#!/bin/bash
set -euo pipefail

BASE_DIR="/home/yichieh/linux_2days/linux_round55"
REPORT="$BASE_DIR/cleanup_report.txt"
DAYS=7

preview_cleanup() {
    {
        echo "Cleanup Preview Report"
        echo "======================"
        echo "Generated at: $(date)"
        echo ""
        echo "Base directory: $BASE_DIR"
        echo "Retention days: $DAYS"
        echo ""

        echo "1. Temporary files (*.tmp)"
        echo "------------------------"
        find "$BASE_DIR" -type f -name "*.tmp" || true
        echo ""

        echo "2. Backup files (*.bak)"
        echo "----------------------"
        find "$BASE_DIR" -type f -name "*.bak" || true
        echo ""

        echo "3. Files older than $DAYS days"
        echo "-----------------------------"
        find "$BASE_DIR" -type f -mtime +"$DAYS" || true
        echo ""

        echo "4. Old log files (*.log, older than $DAYS days)"
        echo "----------------------------------------------"
        find "$BASE_DIR" -type f -name "*.log" -mtime +"$DAYS" || true
        echo ""

        echo "5. Old text reports (*.txt, older than $DAYS days)"
        echo "-------------------------------------------------"
        find "$BASE_DIR" -type f -name "*.txt" -mtime +"$DAYS" || true
        echo ""
    } > "$REPORT"

    echo "Preview report generated: $REPORT"
}

delete_cleanup() {
    echo "Deleting temporary files (*.tmp)..."
    find "$BASE_DIR" -type f -name "*.tmp" -delete

    echo "Deleting backup files (*.bak)..."
    find "$BASE_DIR" -type f -name "*.bak" -delete

    echo "Deleting old log files (*.log, older than $DAYS days)..."
    find "$BASE_DIR" -type f -name "*.log" -mtime +"$DAYS" -delete

    echo "Deleting old text reports (*.txt, older than $DAYS days)..."
    find "$BASE_DIR" -type f -name "*.txt" -mtime +"$DAYS" -delete

    echo "Cleanup completed."
}

show_usage() {
    echo "Usage:"
    echo "  ./cleanup_old_files.sh preview"
    echo "  ./cleanup_old_files.sh delete"
}

main() {
    if [ $# -ne 1 ]; then
        show_usage
        exit 1
    fi

    case "$1" in
        preview)
            preview_cleanup
            ;;
        delete)
            delete_cleanup
            ;;
        *)
            show_usage
            exit 1
            ;;
    esac
}

main "$@"
