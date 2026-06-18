#!/bin/bash
set -euo pipefail

BASE_DIR="/home/yichieh/linux_2days/linux_round53"
REPORT_DIR="$BASE_DIR/reports"
ARCHIVE_DIR="$BASE_DIR/archive"
REPORT_FILE="$REPORT_DIR/system_report.txt"
TIMESTAMP=$(date +"%Y%m%d_%H%M%S")
ARCHIVE_FILE="$ARCHIVE_DIR/system_report_$TIMESTAMP.txt"
KEEP_COUNT=3

prepare_dirs() {
    mkdir -p "$REPORT_DIR" "$ARCHIVE_DIR"
}

generate_report() {
    {
        echo "Linux Archived System Monitoring Report"
        echo "======================================="
        echo "Generated at: $(date)"
        echo ""

        echo "1. System Uptime"
        echo "----------------"
        uptime
        echo ""

        echo "2. Memory Usage"
        echo "---------------"
        free -h
        echo ""

        echo "3. Disk Usage"
        echo "-------------"
        df -h
        echo ""

        echo "4. Project Folder Size"
        echo "----------------------"
        du -sh /home/yichieh/linux_2days
        echo ""

        echo "5. Top Processes Snapshot"
        echo "-------------------------"
        ps aux | head
        echo ""

        echo "6. Bash Processes"
        echo "-----------------"
        pgrep -a bash || true
        echo ""

        echo "7. Cron Process"
        echo "---------------"
        pgrep -a cron || true
        echo ""
    } > "$REPORT_FILE"
}

archive_report() {
    cp "$REPORT_FILE" "$ARCHIVE_FILE"
}

rotate_archive() {
    cd "$ARCHIVE_DIR"

    local old_files
    old_files=$(ls -1t system_report_*.txt 2>/dev/null | tail -n +$((KEEP_COUNT + 1)) || true)

    if [ -n "$old_files" ]; then
        echo "$old_files" | xargs rm -f
    fi
}

main() {
    prepare_dirs
    generate_report
    archive_report
    rotate_archive

    echo "Current report: $REPORT_FILE"
    echo "Archived report: $ARCHIVE_FILE"
    echo "Keep latest archive reports: $KEEP_COUNT"
}

main
