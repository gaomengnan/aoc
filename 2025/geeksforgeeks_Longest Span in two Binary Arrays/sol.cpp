#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  int equalSumSpan(vector<int> &a1, vector<int> &a2) {
    int n = a1.size();
    // int n2 = a2.size();

    vector<int> diffs(n);

    unordered_map<int, int> mp;
    mp[0] = -1;

    int win_sum = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
      diffs[i] = a1[i] - a2[i];
    }

    for (int i = 0; i < n; i++) {
      win_sum += diffs[i];
      if (mp.find(win_sum) != mp.end()) {
        int len = i - mp[win_sum];
        ans = max(ans, len);
        cout << "Found at index: " << i << " with length: " << len << endl;
      } else {
        mp[win_sum] = i;
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> a1 = {0, 1, 1}; // 1
  vector<int> a2 = {1, 1, 0}; // 3
  int result = sol.equalSumSpan(a1, a2);
  cout << "Final result: " << result << endl;
  return 0;
}
