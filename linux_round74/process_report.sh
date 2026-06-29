#!/bin/bash

echo "Process Report"
echo "=============="
echo "Current shell PID: $$"
echo

echo "Top processes by CPU:"
ps aux --sort=-%cpu | head -6

echo
echo "Top processes by memory:"
ps aux --sort=-%mem | head -6

echo
echo "Sleep processes:"
pgrep -a sleep || echo "No sleep process found"
