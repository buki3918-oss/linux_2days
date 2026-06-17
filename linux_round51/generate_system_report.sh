#!/bin/bash
set -euo pipefail

REPORT="/home/yichieh/linux_2days/linux_round51/system_report.txt"
PROJECT_DIR="/home/yichieh/linux_2days"

generate_report() {
    {
        echo "Linux System Monitoring Report"
        echo "=============================="
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
        du -sh "$PROJECT_DIR"
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
    } > "$REPORT"
}

main() {
    generate_report
    echo "System report generated: $REPORT"
}

main
