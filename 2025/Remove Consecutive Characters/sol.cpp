#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  string removeConsecutiveCharacter(string &s) {
    // int n = s.size();
    int pre_key = s[0];
    for (int i = 1; i < s.size();) {
      if (s[i] == pre_key) {
        s.erase(i, 1);
      } else {
        pre_key = s[i];
        i++;
      }
    }
    return s;
  }
};
int main() {
  Solution sol;
  string s = "abcddcba";
  cout << sol.removeConsecutiveCharacter(s) << endl; // Output: 39
  return 0;
}
