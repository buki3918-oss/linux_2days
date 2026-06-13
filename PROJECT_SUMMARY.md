# Project Summary: Linux Engineering Practice

## Overview

This repository documents my step-by-step Linux, shell scripting, Git, and command-line engineering practice.

The project started from basic Linux operations and gradually progressed into safer shell scripting, automation, error handling, and a small log analysis tool.

## Motivation

The purpose of this project is to build practical engineering fundamentals for software development, data engineering, system automation, and semiconductor-related IT or CIM roles.

Instead of only reading commands, I practiced each topic by writing scripts, testing outputs, handling errors, and pushing each stage to GitHub.

## Key Skills Practiced

- Linux command-line operations
- File and directory management
- Git and GitHub workflow
- Bash scripting
- Script arguments
- if / for / while / case
- Shell functions
- Exit status and return code
- Safe error handling
- Bash strict mode
- trap and cleanup mechanism
- README documentation
- Small automation project organization

## Main Project: Safe Log Analyzer

The main project in this repository is:

linux_round40/

Main script:

linux_round40/safe_log_analyzer.sh

The Safe Log Analyzer is an interactive shell script tool that can:

- Show log files
- Search ERROR messages
- Search WARNING messages
- Count log lines
- Generate a log report
- Handle missing log directory safely

This small project demonstrates how basic Linux commands can be combined into a safer and more structured automation tool.

## Selected Highlights

### Shell Script Toolkit

Rounds 32-35 include a Linux toolkit and a refactored function-based version.

Main concepts:

- Interactive menu
- case statement
- function-based design
- file checking
- log searching
- line counting

### Safe Error Handling

Rounds 36-37 focus on reliable script behavior.

Main concepts:

- echo $?
- exit 0
- exit 1
- return 0
- return 1
- checking missing arguments
- checking missing files

### Strict Mode and Cleanup

Rounds 38-39 focus on safer automation scripts.

Main concepts:

- set -e
- set -u
- set -o pipefail
- set -euo pipefail
- trap cleanup EXIT
- trap error_handler ERR
- mktemp

## What This Repository Demonstrates

This repository demonstrates that I can:

- Learn technical tools step by step
- Practice command-line operations seriously
- Write simple but structured shell scripts
- Handle errors safely
- Use Git and GitHub for version control
- Organize a small project with README documentation

## Future Improvements

Future extensions may include:

- sed and awk practice
- cron job automation
- Makefile practice
- shell script testing
- simple CI workflow
- Python and shell integration
- log analysis enhancement
