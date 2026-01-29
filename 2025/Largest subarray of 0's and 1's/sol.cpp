#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int maxLen(vector<int> &arr) {
    int n = arr.size();
    unordered_map<int, int> firstIndex;
    int prefix = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
      // 把 0 当成 -1
      prefix += (arr[i] == 0 ? -1 : 1);

      // 若前缀和为 0，说明从 0 到 i 的子数组平衡
      if (prefix == 0) {
        maxLen = i + 1;
      }

      // 若该前缀和之前出现过，则说明从上一次到现在这段区间平衡
      if (firstIndex.find(prefix) != firstIndex.end()) {
        maxLen = max(maxLen, i - firstIndex[prefix]);
      } else {
        // 只记录第一次出现的位置
        firstIndex[prefix] = i;
      }
    }

    return maxLen;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {1, 0, 1, 1, 1, 0, 0};
  cout << sol.maxLen(arr) << endl; // 输出 6
  return 0;
}
