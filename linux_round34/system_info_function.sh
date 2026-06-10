#!/bin/bash

show_system_info() {
    echo "=== System Info ==="
    echo "User: $(whoami)"
    echo "Path: $(pwd)"
    echo "Date: $(date)"
}

show_system_info
