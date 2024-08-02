#!/bin/bash

# Check if the test directory exists
if [ ! -d "tests" ]; then
  echo "Directory 'test' does not exist."
  exit 1
fi

# Iterate over each test-#.in file in the test directory
for test_file in tests/test*-pkts.in; do
  # Check if there are no matching files
  if [ ! -e "$test_file" ]; then
    echo "No test files found."
    exit 1
  fi
	test_in=${test_file}
	test_out=${test_file%.in}.out
  # Run prog.exe with the current test file as input
  ./firewall.exe < ${test_in} | diff ${test_out} -

  # Optional: Capture the output to a file
  # ./prog.exe < "$test_file" > "${test_file%.in}.out"
done
