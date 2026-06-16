#!/bin/bash
set -euo pipefail

BASE_DIR="/home/yichieh/linux_2days/linux_round48"
RAW_LOG="$BASE_DIR/logs/app.log"
CLEAN_LOG="$BASE_DIR/logs/clean_app.log"
REPORT="$BASE_DIR/reports/log_report.txt"

check_file() {
    if [ ! -f "$RAW_LOG" ]; then
        echo "Error: missing log file: $RAW_LOG"
        exit 1
    fi
}

clean_log() {
    sed '/DEBUG/d' "$RAW_LOG" > "$CLEAN_LOG"
}

generate_report() {
    {
        echo "Scheduled Log Report"
        echo "===================="
        echo "Generated at: $(date)"
        echo ""
        echo "Source log: $RAW_LOG"
        echo "Clean log: $CLEAN_LOG"
        echo ""
        echo "Log level count:"
        awk '
        {
            count[$3]++
        }
        END {
            print "INFO:", count["INFO"]
            print "WARNING:", count["WARNING"]
            print "ERROR:", count["ERROR"]
        }
        ' "$CLEAN_LOG"
        echo ""
        echo "ERROR users:"
        awk '$3 == "ERROR" {
            for (i = 1; i <= NF; i++) {
                if ($i ~ /^user=/) {
                    print $i
                }
            }
        }' "$CLEAN_LOG"
    } > "$REPORT"
}

main() {
    check_file
    clean_log
    generate_report
    echo "Report generated: $REPORT"
}

main
