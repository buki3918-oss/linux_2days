#!/bin/bash
set -euo pipefail

echo "=== Check Safe Log Analyzer Project ==="

check_file() {
    if [ -f "$1" ]; then
        echo "OK: $1"
    else
        echo "Missing: $1"
        exit 1
    fi
}

check_dir() {
    if [ -d "$1" ]; then
        echo "OK: $1"
    else
        echo "Missing: $1"
        exit 1
    fi
}

check_file "README.md"
check_file "safe_log_analyzer.sh"
check_file "safe_log_analyzer_notes.txt"
check_file "log_report.txt"
check_dir "logs"
check_file "logs/app.log"
check_file "logs/server.log"

echo "All project files are ready."
exit 0
