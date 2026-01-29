#include <algorithm>
#include <iostream>
#include <print>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> maxOfMins(vector<int> &arr) {
    int n = arr.size();
    // sort(arr.begin(), arr.end());

    vector<int> ans(n, 0);

    vector<int> left(n), right(n);
    stack<int> s;

    for (int i = 0; i < n; ++i) {
      while (!s.empty() && arr[s.top()] >= arr[i]) {
        s.pop();
      }
      left[i] = s.empty() ? -1 : s.top();
      s.push(i);
    }
    while (!s.empty())
      s.pop();

    for (int i = n - 1; i >= 0; --i) {
      while (!s.empty() && arr[s.top()] >= arr[i]) {
        s.pop();
      }
      right[i] = s.empty() ? n : s.top();
      s.push(i);
    }

    for (int i = 0; i < n; ++i) {
      int len = right[i] - left[i] - 1;
      ans[len - 1] = max(ans[len - 1], arr[i]);
    }



    for (int i = n - 2; i >= 0; --i) {
      ans[i] = max(ans[i], ans[i + 1]);
    }

    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {10, 20, 30};
  auto result = sol.maxOfMins(arr);
  println("result is {}", result);
  return 0;
}
