#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> constructArr(vector<int> &arr) {
    // code here
    int n = 0;
    while (n * (n - 1) / 2 < arr.size()) {
      n++;
    }
    // res[0]=2arr[0]+arr[1]−arr[n−1]
    vector<int> res(n);

    res[0] = (arr[0] + arr[1] - arr[n - 1]) / 2;
    // cout << "res0 " << res[0] << endl;
    for (int i = 1; i < n; ++i) {
        res[i] = arr[i-1] - res[0];
    }

    // cout << n << endl;

    return res;
  }
};

//    4     5     3
//  (0,1) (0,2) (1,2)
//  x x x

int main() {
  Solution sol;
  vector<int> arr = {4, 5, 3};
  vector<int> result = sol.constructArr(arr);
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
