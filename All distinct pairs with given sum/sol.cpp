#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// User function Template for C++
class Solution {
public:
  vector<vector<int>> distinctPairs(vector<int> &arr, int target) {
    // Code here
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;

    int l = 0;
    int r = n - 1;
    while (l < r) {
      int sum = arr[l] + arr[r];
      if (sum > target) {
        r--;
      } else if (sum < target) {
        l++;
      } else {
        res.push_back({arr[l], arr[r]});
        l++;
        r--;
        while (l < r && arr[l] == arr[l - 1])
          l++;

        while (l < r && arr[r] == arr[r + 1])
          r--;
      }
    }
    return res;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {10, 12, 10, 15, -1};
  int target = 125;
  vector<vector<int>> result = sol.distinctPairs(arr, target);
  for (const auto &pair : result) {
    cout << "[" << pair[0] << ", " << pair[1] << "] ";
  }
  cout << endl;
  return 0;
}
