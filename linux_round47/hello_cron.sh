#!/bin/bash
set -euo pipefail

LOG_FILE="/home/yichieh/linux_2days/linux_round47/cron_test.log"

echo "Hello from cron at $(date)" >> "$LOG_FILE"
