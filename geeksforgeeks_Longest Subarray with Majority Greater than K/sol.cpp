#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int longestSubarray(vector<int> &arr, int k) {
    int n = arr.size();
    int ans = 0;
    // 构建 n + 1
    vector<int> sp(n);

    for (int i = 0; i < n; i++) {
      sp[i] = (arr[i] > k ? 1 : -1);
    }

    vector<int> pres(n + 1, 0);

    for (int i = 0; i < n; i++) {
      pres[i + 1] = pres[i] + sp[i];
    }
    // 构建单调递增zhai
    vector<int> stk;

    for (int i = 0; i <= n; i++) {
      if (stk.empty() || pres[i] < pres[stk.back()]) {
        stk.push_back(i);
      }
    }

    for (int r = n; r >= 0; r--) {
      while (!stk.empty() && pres[r] > pres[stk.back()]) {
        int l = stk.back();
        stk.pop_back();
        ans = max(ans, r - l);
      }
    }

    return ans;
  }
};
int main() {
  Solution sol;
  vector<int> arr = {11, 60, 26, 7,  44, 30, 18, 29, 10, 72, 3,  4, 49,
                     77, 23, 21, 20, 34, 20, 99, 21, 70, 9,  74, 41};
  int k = 35;
  cout << sol.longestSubarray(arr, k) << endl;
  return 0;
}
