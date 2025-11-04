#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// User function template for C++
class Solution {
public:
  int findMaximum(vector<int> &arr) {
    // code here
    int n = arr.size();
    int left = 0;
    int right = n - 1;

    while (left <= right) {
      int m1 = left + (right - left) / 3;
      int m2 = right - (right - left) / 3;

      if (arr[m1] < arr[m2]) {
        left = m1 + 1;
      } else {
        right = m2 - 1;
      }
    }
    cout << "Left: " << left << ", Right: " << right << endl;
    return arr[left];
  }
};

int main() {
  Solution sol;
  vector<int> arr = {120, 100, 80, 20, 0};
  cout << "Maximum element is: " << sol.findMaximum(arr) << endl;
  return 0;
}
