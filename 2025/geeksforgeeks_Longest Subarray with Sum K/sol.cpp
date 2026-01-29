#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void printMap(unordered_map<int, int> &mp) {
  cout << "{ ";
  for (auto &[key, val] : mp) {
    cout << key << ":" << val << " ";
  }
  cout << "}" << endl;
}

class Solution {
public:
  int longestSubarray(vector<int> &arr, int k) {
    int n = arr.size();

    unordered_map<int, int> mp;
    mp[0] = -1; // 前缀和为0时，索引为-1

    int win_sum = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
      win_sum += arr[i];

      cout << "i=" << i << ", arr[i]=" << arr[i] << ", win_sum=" << win_sum
           << endl;

      if (mp.find(win_sum - k) != mp.end()) {
        ans = max(ans, i - mp[win_sum - k]);
        cout << "Found sum-k in map, ans updated to " << ans << endl;
      }

      if (mp.find(win_sum) == mp.end()) {
        mp[win_sum] = i;
      }

      cout << "Map now: ";
      printMap(mp);
      cout << "-----------------" << endl;
    }

    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {10, 5, -5, -10, 1, -10};
  int k = 0;
  int result = sol.longestSubarray(arr, k);
  cout << "Final result: " << result << endl;
  return 0;
}
