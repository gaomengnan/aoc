#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int findSubString(string &str) {
    // code here
    int n = str.size();
    unordered_map<int, int> mp;
    unordered_set<int> counter;

    int ans = INT_MAX;

    for (int i = 0; i < n; ++i) {
      counter.insert(str[i] - 'a');
    }
    int start = 0;
    int k = counter.size();
    for (int i = 0; i < n; i++) {
      mp[str[i] - 'a']++;
      while (mp.size() > k) {
        if (--mp[str[start] - 'a'] == 0) {
          mp.erase(str[start] - 'a');
        }
      }

      if (mp.size() == k) {
        ans = min(ans, i - start + 1);
        while (mp.size() == k) {
          if (--mp[str[start] - 'a'] == 0) {
            mp.erase(str[start] - 'a');
          }
          start++;
          if (mp.size() == k) {
            ans = min(ans, i - start + 1);
          }
        }
      }
    }

    return ans;
  }
};
int main() {
  Solution sol;
  string str = "aabcbcdbca";
  cout << sol.findSubString(str) << endl; // Output: 4
  return 0;
}
