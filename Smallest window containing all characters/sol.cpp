#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  string smallestWindow(string &s, string &p) {
    // code here
    int n = s.size();
    int m = p.size();

    unordered_map<char, int> mps;

    for (int i = 0; i < m; i++) {
      mps[p[i]]++;
    }

    int count = 0;
    int left = 0;
    int min_len = INT_MAX;
    int min_start = 0;
    for (int i = 0; i < n; i++) {
      int x = s[i];
      if (mps.find(x) != mps.end()) {
        if (mps.find(x)->second > 0) {
          count++;
        }
        mps[x]--;
      }

      while (count == m) {
        if (i - left + 1 < min_len) {
          min_start = left;
          min_len = i - left + 1;
        }

        int y = s[left];

        if (mps.find(y) != mps.end()) {
          mps[y]++;
          if (mps.find(y)->second > 0) {
            count--;
          }
        }
        left++;
      }
    }

    // cout << min_start << min_len << endl;

    if (min_len == INT_MAX) {
      return "";
    }

    return s.substr(min_start, min_len);
  }
};

int main() {
  Solution sol;
  string s = "ADOBECODEBANC";
  string p = "ABC";
  cout << sol.smallestWindow(s, p) << endl; // Output: "BANC"
  return 0;
}
