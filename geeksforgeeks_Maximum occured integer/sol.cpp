#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxOccured(vector<int> &L, const vector<int> &R) {
    int n = L.size();
    vector<int> vec(1000001, 0);
    // vector<int> preSum(n);

    for (int i = 0; i < n; i++) {
      vec[L[i]] ++;
      vec[R[i]+1] --;
    }

    int maxVal = vec[0];
    int maxIdx = 0;

    for (int i = 1; i < 1000001; i++) {
      vec[i] += vec[i-1];
      if (vec[i] > maxVal) {
        maxVal = vec[i];
        maxIdx = i;
      }
    }
    return maxIdx;
  }
};

int main() {
  // 测试原来的功能
  Solution sol;
  vector<int> L = {1, 4, 3, 1};
  vector<int> R = {15, 8, 5, 4};
  cout << "Maximum occurred integer: " << sol.maxOccured(L, R) << endl;

  return 0;
}
