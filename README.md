# Linux Engineering Practice

This repository records my Linux, shell script, Git, and engineering fundamentals practice.

The goal of this project is to build practical command-line skills step by step, from basic Linux commands to safer shell scripting and small automation tools.

## Purpose

This repository is used to practice:

- Linux command-line operations
- File and directory management
- Git and GitHub workflow
- Shell script basics
- Bash functions
- Error handling
- Bash strict mode
- Trap and cleanup mechanism
- Small automation project development
- Project documentation with README

## Learning Progress

### Basic Linux and Git Practice

- Linux basic commands
- File operations
- Text processing
- Git add, commit, push
- GitHub remote repository workflow

### Shell Script Practice

- Script execution permission
- Arguments
- if statements
- for loops
- while loops
- case menu
- functions
- exit status
- safe error handling
- strict mode
- trap cleanup

### Small Project

The main small project in this repository is:

linux_round40/Safe Log Analyzer

This project is a shell script tool for analyzing log files safely.

Main features:

- Show log files
- Search ERROR messages
- Search WARNING messages
- Count log lines
- Generate a log report
- Handle missing log directory safely

Project folder:

linux_round40/

Main script:

linux_round40/safe_log_analyzer.sh

Project README:

linux_round40/README.md

## Selected Practice Rounds

### Rounds 30-31: Loop Practice

Topics:

- for loop
- while loop
- read input
- file line-by-line processing

### Rounds 32-33: Menu and Toolkit Practice

Topics:

- case menu
- interactive shell script
- Linux Toolkit script

### Rounds 34-35: Function and Refactoring

Topics:

- shell function
- function arguments
- refactoring toolkit into function version

### Rounds 36-37: Exit Status and Safe Error Handling

Topics:

- echo $?
- exit 0
- exit 1
- return 0
- return 1
- safe argument checking
- safe file checking

### Rounds 38-39: Strict Mode and Trap

Topics:

- set -e
- set -u
- set -o pipefail
- set -euo pipefail
- trap cleanup EXIT
- trap error_handler ERR
- mktemp

### Rounds 40-41: Safe Log Analyzer Project

Topics:

- small shell script project
- project README
- project check script
- GitHub-style project organization

## How to Run the Safe Log Analyzer

Go to the project folder:

    cd linux_round40

Give executable permission:

    chmod 755 safe_log_analyzer.sh

Run the tool:

    ./safe_log_analyzer.sh

Run the project check script:

    ./check_project.sh

## Skills Demonstrated

This repository demonstrates:

- Basic Linux operations
- Bash scripting
- Shell script automation
- Defensive programming
- Error handling
- Git version control
- GitHub project organization
- README documentation

## Future Improvements

Future practice may include:

- sed and awk
- cron jobs
- Makefile
- shell script testing
- simple CI workflow
- Linux process monitoring
- log analysis enhancement
- Python and shell integration

## Notes

This repository is part of my long-term self-study plan for building engineering fundamentals.

The focus is not only to memorize commands, but also to understand how to build safer and more maintainable command-line tools.
