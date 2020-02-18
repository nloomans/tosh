#!/bin/sh
cd "$(dirname "$0")/.." || exit 1
! norminette "$@" src/**/*.h | tee /dev/stderr | grep -q Error
