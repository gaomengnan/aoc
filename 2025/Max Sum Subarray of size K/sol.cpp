#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubarraySum(vector<int> &arr, int k) {
    int n = arr.size();
    int ans = 0;

    int win_sum = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
      while ((i - j + 1) > k) {
        win_sum -= arr[j];
        j++;
      }
      win_sum += arr[i];
      ans = max(win_sum, ans);
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {100, 200, 300, 400};
  int k = 1;
  cout << sol.maxSubarraySum(arr, k) << endl; // Output: 39
  return 0;
}
