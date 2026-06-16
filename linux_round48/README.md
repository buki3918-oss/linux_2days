# Scheduled Log Report Project

This project is a small Linux automation project that generates a scheduled log summary report.

It combines:

- shell script
- sed
- awk
- cron
- project folder organization

## Project Purpose

The purpose of this project is to practice building a small Linux automation workflow.

The script reads an application log, removes DEBUG lines, counts log levels, extracts ERROR users, and generates a summary report.

## Folder Structure

linux_round48/
- README.md
- run_report.sh
- bin/generate_log_report.sh
- logs/app.log
- logs/clean_app.log
- reports/log_report.txt
- project_notes.txt
- structure_notes.txt

## Main Script

bin/generate_log_report.sh

## Input

logs/app.log

This file contains sample application logs with:

- INFO
- DEBUG
- WARNING
- ERROR

## Output

reports/log_report.txt

The report contains:

- generated time
- source log path
- clean log path
- log level count
- ERROR users

## How to Run Manually

Run:

./run_report.sh

Or run the main script directly:

./bin/generate_log_report.sh

## Example Output

Scheduled Log Report
====================
Generated at: Tue Jun 16 23:48:01 CST 2026

Log level count:
INFO: 4
WARNING: 2
ERROR: 2

ERROR users:
user=Bob
user=Cindy

## Cron Test

This project was tested with cron using:

* * * * * /home/yichieh/linux_2days/linux_round48/bin/generate_log_report.sh

This means the script runs every minute.

The test cron job was removed after testing.

## Technical Concepts Used

- sed for removing DEBUG lines
- awk for counting log levels
- awk pattern matching for extracting user fields
- shell script functions
- absolute paths
- cron scheduling
- project folder organization

## Key Lesson

A useful Linux automation project should have a clear structure:

- bin/ for scripts
- logs/ for input logs
- reports/ for generated reports
- README.md for explanation
