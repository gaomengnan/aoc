#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int substrCount(string &s, int k) {
    int n = s.size();
    unordered_map<char, int> mp;

    int left = 0;
    int ans = 0;

    for (int r = 0; r < n; ++r) {
      mp[s[r] - 'a']++;
      while (r - left + 1 > k) {
        if (--mp[s[left] - 'a'] == 0) {
          mp.erase(s[left] - 'a');
        }
        left++;
      }

      if (mp.size() == k - 1 && r - left + 1 == k) {
        ans++;
      }
    }

    return ans;
  }
};
int main() {

  string s = "clwst";
  int k = 4;

  Solution sol;
  cout << sol.substrCount(s, k) << endl;

  return 0;
}
