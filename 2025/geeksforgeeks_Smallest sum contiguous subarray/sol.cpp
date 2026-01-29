#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int smallestSumSubarray(vector<int> &a) {
    int n = a.size();
    int win_sum = 0;
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
      int x = a[i];
      win_sum += x;
      if (win_sum > x) {
        win_sum = x;
      }
      ans = min(ans, win_sum);
    }

    return ans;
  }
};
int main() {
  Solution sol;
  vector<int> arr = {3, -4, 2, -3, -1, 7, -5};
  cout << sol.smallestSumSubarray(arr) << endl; // Output: -20
  return 0;
}
