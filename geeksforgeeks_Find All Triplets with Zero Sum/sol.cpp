#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  void getPairs(vector<int> &arr, int idx, int target, int firstEle,
                vector<vector<int>> &ans) {
    unordered_map<int, vector<int>> mp;
    int n = arr.size();
    // vector<vector<int>> ans;

    for (int i = idx; i < n; i++) {
      int x = arr[i];
      if (mp.find(target - x) != mp.end()) {
        vector<int> matched = mp.find(target - x)->second;
        for (int j = 0; j < matched.size(); j++) {
          ans.push_back({
              firstEle,
              matched[j],
              i,
          });
        }
      }
      mp[x].push_back(i);
    }
    // return ans;
  }

  vector<vector<int>> findTriplets(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n - 2; i++) {
      int x = arr[i];
      int rem = 0 - x;
      getPairs(arr, i + 1, rem, i, ans);
    }

    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {0, -1, 2, -3, 1};
  vector<vector<int>> triplets = sol.findTriplets(arr);

  for (const auto &triplet : triplets) {
    cout << "[";
    for (size_t i = 0; i < triplet.size(); ++i) {
      cout << triplet[i];
      if (i < triplet.size() - 1)
        cout << ", ";
    }
    cout << "]" << endl;
  }

  return 0;
}
