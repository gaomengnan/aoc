#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// User function Template for C++
class Solution {
public:
  vector<vector<int>> findAllPairs(vector<int> &arr, int target) {
    // Code here

    int n = arr.size();
    vector<vector<int>> res;
    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < n; ++i) {
      int needed = target - arr[i];
      if (mp.find(needed) != mp.end()) {
        vector<int> sc = mp.find(needed)->second;

        for (int j = 0; j < sc.size(); j++) {
          res.push_back({sc[j], i});
        }
      }
      mp[arr[i]].push_back(i);
    }

    sort(res.begin(), res.end(),
         [](const vector<int> &a, const vector<int> &b) {
           if (a[0] != b[0]) {
             return a[0] < b[0]; // 先按第一个元素升序
           }
           return a[1] < b[1]; // 第一个相等时按第二个元素升序
         });

    return res;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {1, 2, 3, 4, 5};
  int target = 5;
  vector<vector<int>> result = sol.findAllPairs(arr, target);

  for (const auto &pair : result) {
    cout << "[" << pair[0] << ", " << pair[1] << "]" << endl;
  }

  return 0;
}
