// Given a string s, your task is to find the longest palindromic substring
// within s. A substring is a contiguous sequence of characters within a string,
// defined as s[i...j] where 0 ≤ i ≤ j < len(s). A palindrome is a string that
// reads the same forward and backward. More formally, s is a palindrome if
// reverse(s) == s. Note: If there are multiple palindromic substrings with the
// same length, return the first occurrence of the longest palindromic substring
// from left to right.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string longestPalindrome(string &s) {
    int n = s.length();
    if (n == 0)
      return "";

    string output = s.substr(0, 1);

    for (int i = 1; i < n; ++i) {
      int x, y;

      // 第一种：偶数中心，...a a...
      if (s[i] == s[i - 1]) {
        // 先从 (i-1, i) 开始扩
        x = i - 1;
        y = i;
        while (x > 0 && y < n - 1 && s[x - 1] == s[y + 1]) {
          x--;
          y++;
        }
        if (y - x + 1 > (int)output.size()) {
          output = s.substr(x, y - x + 1);
        }

        // 再额外试一次奇数中心 (i, i)
        x = i;
        y = i;
        while (x > 0 && y < n - 1 && s[x - 1] == s[y + 1]) {
          x--;
          y++;
        }
        if (y - x + 1 > (int)output.size()) {
          output = s.substr(x, y - x + 1);
        }
      }
      // 第二种：只试奇数中心
      else { // s[i] != s[i - 1]
        x = i;
        y = i;
        while (x > 0 && y < n - 1 && s[x - 1] == s[y + 1]) {
          x--;
          y++;
        }
        if (y - x + 1 > (int)output.size()) {
          output = s.substr(x, y - x + 1);
        }
      }
    }

    return output;
  }
};

int main() {
  Solution sol;
  vector<pair<string, string>> tests = {
      {"forgeeksskeegfor",
       "geeksskeeg"},               // empty string represents no characters
      {"a", "a"},                   // single character is itself a palindrome
      {"cbbc", "cbbc"},             // even-length palindrome spans entire
      {"babad", "bab"},             // odd-length palindrome (first longest)
      {"racecar", "racecar"},       // entire word is palindrome
      {"abacdfgdcaba", "aba"},      // palindrome in the middle
      {"abcbaabcba", "abcbaabcba"}, // repeated palindrome
  };

  for (const auto &[input, expected] : tests) {
    string mutable_input = input;
    string result = sol.longestPalindrome(mutable_input);
    cout << "Input: \"" << input << "\" | Expected: \"" << expected
         << "\" | Output: \"" << result << "\"" << endl;
  }

  return 0;
}

// babad
// bab
