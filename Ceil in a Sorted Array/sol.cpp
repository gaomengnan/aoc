#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// User function Template for C++
class Solution {
public:
  int findCeil(vector<int> &arr, int x) {
    // code here
    int left = 0;
    int right = arr.size() - 1;
    int res = -1;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] < x) {
        left = mid + 1;
      } else {
        res = mid;
        right = mid - 1;
      }
    }
    return res;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {1, 1, 10, 10, 10, 11, 12, 19};
  int x = 10;
  cout << sol.findCeil(arr, x) << endl; // Output: 8
  return 0;
}
