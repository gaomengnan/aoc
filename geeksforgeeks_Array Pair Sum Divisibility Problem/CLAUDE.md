# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

Project type: Small C++17 console program solving “Array Pair Sum Divisibility Problem”. No build system, tests, or linting configured.

Common commands
- Build: g++ -std=c++17 -O2 -Wall -Wextra -pedantic sol.cpp -o main
- Run: ./main
- Clean: rm -f main

Notes on running/tests
- There is no test suite. To try examples, edit main() in sol.cpp to modify arr and k, rebuild, then run.
- The checked-in main file is a macOS binary; prefer rebuilding locally from sol.cpp.

High-level structure and logic
- sol.cpp defines class Solution with bool canPair(vector<int>& arr, int k) implementing remainder-bucketing:
  - Counts occurrences of rem = ((num % k) + k) % k to handle negatives.
  - Validates counts: rem==0 requires even count; if k even, rem==k/2 requires even count; otherwise remCount[rem] must equal remCount[k - rem].
  - Returns true iff all buckets satisfy constraints.
- main() constructs a sample arr and k, invokes canPair, prints "true"/"false".
- README.org contains the problem description and example.

Conventions
- Uses C++17 STL (vector, unordered_map, iostream) and standard warnings recommended in the build command.
- No external dependencies or configuration files are present.