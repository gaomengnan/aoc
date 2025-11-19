#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  string countSort(string s) {
    int n = s.size();
    vector<int> tem;

    for (char c : s) {
      tem.push_back(c - 'a'); // 'a'->0, 'b'->1, ...
    }

    int maxval = 0;
    // 计数
    for (int i = 0; i < n; i++) {
      maxval = max(maxval, tem[i]);
    }
    vector<int> cnt(maxval + 1, 0);
    for (int i = 0; i < n; ++i) {
      cnt[tem[i]]++;
    }
    // 计算前缀和
    for (int i = 1; i <= maxval; ++i) {
      cnt[i] += cnt[i - 1];
    }
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; --i) {
      ans[cnt[tem[i]] - 1] = tem[i];
      cnt[tem[i]]--;
    }

    string result;
    for (int n : ans) {
      result += n + 'a';
    }

    return result;
  };
};
int main() {
  Solution sol;
  string s = "leetcode";
  string sorted = sol.countSort(s);
  cout << "sorted: " << sorted << endl;
  return 0;
}
