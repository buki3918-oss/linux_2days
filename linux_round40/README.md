# Safe Log Analyzer

This project is a small Linux shell script tool for safely analyzing log files.

It was created as Linux Round 40 practice.

## Project Purpose

The purpose of this project is to practice building a structured shell script with:

- Bash strict mode
- Functions
- Case menu
- Safe error handling
- Log searching
- Line counting
- Report generation
- Exit status handling

## Folder Structure

linux_round40/
- README.md
- safe_log_analyzer.sh
- safe_log_analyzer_notes.txt
- log_report.txt
- logs/app.log
- logs/server.log

## Main Script

safe_log_analyzer.sh

## Features

The tool provides an interactive menu:

1. Show log files
2. Search ERROR
3. Search WARNING
4. Count log lines
5. Generate report
6. Quit

## How to Run

Give the script executable permission:

chmod 755 safe_log_analyzer.sh

Run the script:

./safe_log_analyzer.sh

## Example Output: Search ERROR

File: logs/app.log
ERROR: database connection failed
ERROR: timeout

File: logs/server.log
ERROR: service unavailable

## Example Output: Count Log Lines

logs/app.log: 7 lines
logs/server.log: 6 lines
Total lines: 13

## Generated Report

The tool can generate:

log_report.txt

The report includes:

- Generated time
- Log file list
- Line count
- ERROR summary
- WARNING summary

## Error Handling Test

If the logs directory does not exist, the script prints:

Error: log directory not found: logs

The exit status is 1.

## Technical Concepts Used

- set -euo pipefail
- function
- case
- read
- if
- for
- grep
- wc -l
- trap cleanup EXIT
- trap error_handler ERR
- exit 0
- exit 1

## What I Learned

Through this project, I learned how to combine basic Linux shell commands into a safer and more structured automation tool.

A shell script should not only work correctly in normal cases, but also stop safely when errors happen.
