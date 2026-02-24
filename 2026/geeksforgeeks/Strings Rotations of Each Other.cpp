// You are given two strings s1 and s2, of equal lengths. The task is to check
// if s2 is a rotated version of the string s1. Note: A string is a rotation of
// another if it can be formed by moving characters from the start to the end
// (or vice versa) without rearranging them.

// 如果 ‎`s1` 和 ‎`s2` 长度不等，直接 ‎`false`。

// 如果长度相等，把 ‎`s1` 拼成 ‎`s1 + s1`，比如 ‎`"abcd"` →
// ‎`"abcdabcd"`，

// 如果 ‎`s2` 是这个长串的子串，比如 ‎`"cdab"` 在
// ‎`"abcdabcd"` 中出现，那就是旋转。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool areRotations(string &s1, string &s2) {
    if (s1.size() != s2.size())
      return false;
    string s = s1 + s2;

    return s.find(s2) == string::npos;

  }
};

int main() {
  Solution sol;

  // // Test 1: Normal rotation
  // string s1_1 = "abcd";
  // string s2_1 = "cdab";
  // cout << "Test 1: " << s1_1 << " and " << s2_1 << " - "
  //      << (sol.areRotations(s1_1, s2_1) ? "true" : "false") << endl;

  // // Test 2: Same string (rotation by 0)
  // string s1_2 = "hello";
  // string s2_2 = "hello";
  // cout << "Test 2: " << s1_2 << " and " << s2_2 << " - "
  //      << (sol.areRotations(s1_2, s2_2) ? "true" : "false") << endl;

  // Test 3: Not a rotation
  string s1_3 = "abcde";
  string s2_3 = "acdeb";
  cout << "Test 3: " << s1_3 << " and " << s2_3 << " - "
       << (sol.areRotations(s1_3, s2_3) ? "true" : "false") << endl;

  // // Test 4: Different lengths
  // string s1_4 = "abc";
  // string s2_4 = "abcd";
  // cout << "Test 4: " << s1_4 << " and " << s2_4 << " - "
  //      << (sol.areRotations(s1_4, s2_4) ? "true" : "false") << endl;
  //
  // // Test 5: Single character
  // string s1_5 = "a";
  // string s2_5 = "a";
  // cout << "Test 5: " << s1_5 << " and " << s2_5 << " - "
  //      << (sol.areRotations(s1_5, s2_5) ? "true" : "false") << endl;
  //
  // // Test 6: Rotation at end
  // string s1_6 = "xyz";
  // string s2_6 = "yzx";
  // cout << "Test 6: " << s1_6 << " and " << s2_6 << " - "
       // << (sol.areRotations(s1_6, s2_6) ? "true" : "false") << endl;

  return 0;
}
