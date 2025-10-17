#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// User function template for C++
class Solution {
public:
  int search(string &pat, string &txt) {
    int k = pat.size();

    int left = 0;
    int ans = 0;

    unordered_map<int, int> mp;
    unordered_map<int, int> pat_map;

    for (int i = 0; i < pat.size(); ++i) {
      pat_map[pat[i] - 'a']++;
    }

    for (int right = 0; right < txt.size(); ++right) {
      mp[txt[right] - 'a']++;
      while (right - left + 1 > k) {
        if (--mp[txt[left] - 'a'] == 0) {
          mp.erase(txt[left] - 'a');
        }
        left++;
      }

      if (right - left + 1 == k && mp == pat_map) {
        ans++;
      }
    }

    return ans;
  }
};

int main() {
  string pat = "aaba";
  string txt = "aabaabaa";
  Solution sol;
  cout << sol.search(pat, txt) << endl; // Output: 2
  return 0;
}
