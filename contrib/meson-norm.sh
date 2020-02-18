#!/bin/sh
cd "$(dirname "$0")/.." || exit 1
! norminette "$@" src/**/*.h 2>/dev/null | tee /dev/stderr | grep -q Error
