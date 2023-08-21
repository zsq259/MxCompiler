#!/bin/bash

set -e

sed -n '/=== input ===/,/=== end ===/{//!p}' "$2" >test.in
sed -n '/=== output ===/,/=== end ===/{//!p}' "$2" >test.ans
exitCode=$(grep 'ExitCode:' "$2" | sed 's/ExitCode: //g')

echo 'compile to riscv32m'
$1 -S $2 >test.s

echo 'run ravel'

ravelOut=$(ravel --oj-mode 2>&1)

ec=$(grep 'exit code:' <<< "$ravelOut" | sed 's/exit code: //g')

if [[ "$ec" -ne "$exitCode" ]]; then
	echo 'exit code not match, should be ' "$exitCode" ' but got ' $?
	exit 1
fi

echo 'compare output'
diff -ZB test.out test.ans