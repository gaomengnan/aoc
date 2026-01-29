#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int smallestSubWithSum(int x, vector<int> &arr) {
    // Your code goes here
    int n = arr.size();
    int win_sum = 0;
    int start = 0;
    int ans = INT_MAX;

    for (int i = 0; i < n; ++i) {
      win_sum += arr[i];
      while (win_sum > x) {
        ans = min(ans, i - start + 1);
        win_sum -= arr[start];
        start++;
      }
    }
    if (ans == INT_MAX) return 0;

    return ans;
  };
};

int main() {
  Solution sol;
  vector<int> arr = {1, 10, 5, 2, 7};
  int x = 100;
  cout << sol.smallestSubWithSum(x, arr) << endl; // Output: 3
  return 0;
}
