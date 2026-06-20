#!/bin/bash
set -euo pipefail

BASE_DIR="/home/yichieh/linux_2days/linux_round57"
LOG_DIR="$BASE_DIR/logs"
REPORT_DIR="$BASE_DIR/reports"
REPORT_FILE="$REPORT_DIR/search_report.txt"

show_usage() {
    echo "Usage:"
    echo "  ./search_logs.sh KEYWORD"
    echo ""
    echo "Example:"
    echo "  ./search_logs.sh ERROR"
    echo "  ./search_logs.sh WARNING"
}

check_args() {
    if [ $# -ne 1 ]; then
        show_usage
        exit 1
    fi
}

prepare_dirs() {
    mkdir -p "$REPORT_DIR"
}

search_logs() {
    local keyword="$1"

    {
        echo "Log Search Report"
        echo "================="
        echo "Generated at: $(date)"
        echo ""
        echo "Log directory: $LOG_DIR"
        echo "Keyword: $keyword"
        echo ""

        echo "1. Matched Lines"
        echo "----------------"
        find "$LOG_DIR" -type f -name "*.log" -print0 | xargs -0 grep -nH "$keyword" || true
        echo ""

        echo "2. Match Count by File"
        echo "----------------------"
        grep -c "$keyword" "$LOG_DIR"/*.log || true
        echo ""

        echo "3. ERROR or WARNING Summary"
        echo "---------------------------"
        find "$LOG_DIR" -type f -name "*.log" -print0 | xargs -0 grep -nH -E "ERROR|WARNING" || true
        echo ""
    } > "$REPORT_FILE"

    echo "Search report generated: $REPORT_FILE"
}

main() {
    check_args "$@"
    prepare_dirs
    search_logs "$1"
}

main "$@"
