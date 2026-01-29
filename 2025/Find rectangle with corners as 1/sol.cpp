#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool ValidCorner(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int ma_count = 0;
        for (int k = 0; k < m; k++) {
          int ma = mat[i][k] + mat[j][k];
          if (ma == 2) {
            ma_count++;
          }
          if (ma_count == 2)
            return true;
        }
      }
    }
    return false;
  }
};

int main() {
  Solution sol;
  // 只有  0 1
  vector<vector<int>> mat = {{1}, {1}, {1}};
  cout << sol.ValidCorner(mat) << endl;
  return 0;
}
