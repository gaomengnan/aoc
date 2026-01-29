# Agent Guidelines for Longest Substring with K Uniques

## Build/Test Commands
- No build system configured - implement solutions in preferred language
- Test with provided examples: s="aabacbebebe", k=3 → 7; s="aaaa", k=2 → -1
- Validate edge cases: empty string, k=0, k>26, k>string length

## Code Style Guidelines
- Use sliding window technique for optimal O(n) solution
- Handle edge cases: return -1 when no valid substring exists
- Prefer hash maps/dictionaries for character frequency tracking
- Variable names: use descriptive names like `max_length`, `char_count`, `window_start`
- Function signature: `def longest_substring_k_uniques(s: str, k: int) -> int`
- Add comments explaining window expansion/contraction logic