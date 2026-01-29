#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

class Solution {
public:
  vector<int> findMean(vector<int> &arr, vector<int> &q) {
    int n = arr.size();

    vector<int> preSums(n);

    preSums[0] = arr[0];

    for (int i = 1; i < n; i++) {
      preSums[i] = arr[i] + preSums[i - 1];
    }

    vector<int> ans;

    int i = 0;
    while (i < q.size()) {
      int l = q[i];
      int r = q[i + 1];
      //  0 --- 2
      int ysum = (l == 0) ? preSums[r] : preSums[r] - preSums[l-1];
      int floored = static_cast<int>(floor(ysum/(r-l+1))); // 向下取整
      ans.push_back(floored);
      // cout << floored << endl;
      i = i + 2;
    }
    return ans;
  };
};

int main() {
  Solution sol;
  vector<int> arr = {6, 7, 8, 10};
  vector<int> q = {0, 3, 1, 2};
  vector<int> result = sol.findMean(arr, q);
  for (int mean : result) {
    cout << mean << " ";
  }
  cout << endl;
  return 0;
}
