#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  bool isSorted(vector<int> &arr) {
    for (int i = 1; i < arr.size(); i++) {
      if (arr[i] - arr[i - 1] < 0) {
        return false;
      }
    }
    return true;
  };
};

int main() {
  Solution sol;
  vector<int> arr1 = {1, 2, 2, 3, 4};
  vector<int> arr2 = {3, 1, 4, 2};
  cout << (sol.isSorted(arr1) ? "true" : "false") << endl; // true
  cout << (sol.isSorted(arr2) ? "true" : "false") << endl; // false
  return 0;
}
