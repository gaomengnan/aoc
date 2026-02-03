#include <vector>
using namespace std;

class Solution {
public:
  int lis(vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n);

    for (int i = 0; i < n; ++i) {
      dp[i] = 1;
    }

    int ans = 1;
    for (int i = 0; i < n; ++i) {

      for (int j = 0; j < i; ++j) {
        if (arr[i] > arr[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
          if (dp[i] == n) {
            return n;
          }
        }
      }
      ans = max(ans, dp[i]);
    }

    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
  int result = sol.lis(arr);
  printf("Length of Longest Increasing Subsequence is %d\n", result);
  return 0;
}
