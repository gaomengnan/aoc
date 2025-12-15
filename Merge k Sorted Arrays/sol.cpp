#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> mergeArrays(vector<vector<int>> &mat) {
    // Code here
    priority_queue<int, vector<int>, greater<int>> minhap;

    int m = mat.size();
    int n = mat[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; ++j) {
        minhap.push(mat[i][j]);
      }
    }

    vector<int> result;

    while (!minhap.empty()) {
      result.push_back(minhap.top());
      minhap.pop();
    }

    return result;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> mat = {{1, 3, 5}, {2, 4, 6}, {0, 7, 8}};
  sol.mergeArrays(mat);
  return 0;
}
