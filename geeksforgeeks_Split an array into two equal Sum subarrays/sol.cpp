#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool canSplit(vector<int> &arr) {
    int n = arr.size();
    vector<int> lefts(n);
    vector<int> rights(n);
    lefts[0] = arr[0];
    rights[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++) {
      lefts[i] = arr[i] + lefts[i - 1];
    }

    for (int i = n - 2; i > 0; i--) {
      rights[i] = arr[i] + rights[i + 1];
    };

    for (int i = 0; i < n - 1; i++) {
      if (lefts[i] == rights[i + 1]) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution sol;
  vector<int> arr1 = {1, 2, 3, 4, 5, 5};
  cout << sol.canSplit(arr1) << endl; // Output: true
  vector<int> arr2 = {4,3,2,1};
  cout << sol.canSplit(arr2) << endl; // Output: true
}
