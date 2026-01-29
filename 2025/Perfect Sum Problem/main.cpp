#include <vector>
using namespace std;

class Solution {
public:
  int perfectSum(vector<int> &arr, int target) {
    long long MOD = 1e9 + 7;
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int num : arr) {
      for (int t = target; t >= 0; t--) {
        if (t - num >= 0) {
          dp[t] = (dp[t] + dp[t - num]) % MOD;
        }
      }
    }
    return dp[target];
  }
};

int main() {
  Solution sol;
  vector<int> arr = {1, 2, 3, 4, 5};
  int target = 5;
  int result = sol.perfectSum(arr, target);
  printf("Result: %d\n", result);
  return 0;
}
