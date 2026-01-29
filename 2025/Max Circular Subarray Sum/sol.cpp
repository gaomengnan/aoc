#include <algorithm>
#include <iostream>
#include <print>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int maxCircularSum(vector<int> &arr) {
    // code here
    int n = arr.size();
    int cur_max = 0;
    int cur_min = 0;
    int max_val = arr[0];
    int min_val = arr[0];

    int total = 0;

    for (int i = 0; i < n; i++) {
      cur_max += arr[i];
      cur_min += arr[i];

      max_val = max(max_val, cur_max);
      min_val = min(min_val, cur_min);

      if (cur_max < 0) {
        cur_max = 0;
      }
      if (cur_min > 0) {
        cur_min = 0;
      }
      total += arr[i];
    }
    if (total < 0) {
      return max_val;
    }
    return max(max_val, total - min_val);
  }
};

int main() {
  Solution sol;
  vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
  cout << sol.maxCircularSum(arr) << endl; // Expected output: 12
  return 0;
}
