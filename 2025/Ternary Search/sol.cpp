#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int findMinIndex(vector<int> &arr) {
    // code here
    int n = arr.size();
    int l = 0;
    int r = n - 1;

    int midIndex = 0;
    while (l <= r) {

      int m1 = l + (r - l) / 3;
      int m2 = r - (r - l) / 3;
      if (arr[m1] == arr[m2]) {
        l = m1 + 1;
        r = m2 - 1;
        midIndex = m1;
        continue;
      }
      if (arr[m1] < arr[m2]) {
        r = m2 - 1;
        midIndex = m1;
      } else {
        l = m1 + 1;
        midIndex = m2;
      }
    }


    return midIndex;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {9, 7, 5, 2, 3, 6, 10};
  cout << sol.findMinIndex(arr) << endl; // Output: 1
  return 0;
}
