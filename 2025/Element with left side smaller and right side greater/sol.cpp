#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int findElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> lefts(n, 0);
    vector<int> rights(n, 0);
    int maxVal = INT_MIN;
    for (int i = 0; i < n; i++) {
      lefts[i] = maxVal;
      maxVal = max(maxVal, arr[i]);
    }

    int minVal = INT_MAX;
    for (int i = n - 1; i >= 0; --i) {
      rights[i] = minVal;
      minVal = min(minVal, arr[i]);
    }
    for (int i = 1; i < n-1; i++) {
      if (arr[i] > lefts[i] && arr[i] < rights[i]) {
        return arr[i];
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {56, 61, 55, 84, 51, 26, 51, 23, 44, 68};
  // 0 5 -5 33 -23 -25 28 -28 21 24
  int index = sol.findElement(arr);
  cout << "Index of the element: " << index << endl;
  return 0;
}
