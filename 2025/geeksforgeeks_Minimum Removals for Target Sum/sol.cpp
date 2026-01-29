#include <climits>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
public:
  int minRemovals(vector<int> &arr, int k) {
    int tot = accumulate(arr.begin(), arr.end(), 0);
    int target = tot - k;

    int n = arr.size();

    // cout << target << endl;

    int i = 0;
    int j = 0;
    int win_sum = 0;
    int ans = INT_MAX;
    while (j < n) {
      win_sum += arr[j];
      // cout << win_sum << endl;
      if (win_sum == target) {
        ans = min(ans, i + (n - 1 - j));
        j++;
        // break;
      } else if (win_sum < target) {
        j++;
      } else {
        win_sum -= arr[i];
        win_sum -= arr[j];
        i++;
        // j--;
      }
    }
    // cout << ans << endl;
    if (ans == INT_MAX) {
      return -1;
    }
    return ans;
  }
};
int main() {
  Solution sol;
  vector<int> arr = {5,2,3,1,1};
  int k = 5;
  cout << sol.minRemovals(arr, k) << endl;
  return 0;
}
