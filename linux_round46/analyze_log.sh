#!/bin/bash
set -euo pipefail

RAW_LOG="raw_app.log"
CLEAN_LOG="clean_app.log"
REPORT="summary_report.txt"

check_file() {
    if [ ! -f "$RAW_LOG" ]; then
        echo "Error: missing file $RAW_LOG"
        exit 1
    fi
}

clean_log() {
    sed '/DEBUG/d' "$RAW_LOG" > "$CLEAN_LOG"
}

generate_report() {
    {
        echo "Log Summary Report"
        echo "=================="
        echo "Generated at: $(date)"
        echo ""
        echo "Source file: $RAW_LOG"
        echo "Clean file: $CLEAN_LOG"
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
    echo "Analysis finished."
    echo "Report: $REPORT"
}

main
