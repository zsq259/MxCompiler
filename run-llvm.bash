#!/bin/bash

set -e

sed -n '/=== input ===/,/=== end ===/{//!p}' "$2" >input.txt
sed -n '/=== output ===/,/=== end ===/{//!p}' "$2" >ans.txt
exitCode=$(grep 'ExitCode:' "$2" | sed 's/ExitCode: //g')

echo 'compile to llvm IR'
$1 -emit-llvm $2 >test.ll
echo 'compile to binary'
clang-15 test.ll builtin.ll -o binary -m32
echo 'run binary'

set +e
./binary <input.txt >output.txt
if [[ $? -ne $exitCode ]]; then
	echo 'exit code not match, should be ' "$exitCode" ' but got ' $?
	exit 1
fi
set -e
echo 'compare output'
diff -qZB ans.txt output.txt