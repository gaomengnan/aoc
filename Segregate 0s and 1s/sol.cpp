#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// User function template for C++

class Solution {
public:
  void segregate0and1(vector<int> &arr) {
    int n = arr.size();

    int left = 0;
    int right = n - 1;

    while (left < right) {

      while (left < right && arr[left] == 0) {
        left++;
      }

      while (left < right && arr[right] == 1) {
        right--;
      }
      if (left < right) {
        swap(arr[left], arr[right]);
      }
    }
  }
};

int main() {
  Solution sol;
  vector<int> arr = {0, 1, 0, 1, 1, 0, 0, 1};
  sol.segregate0and1(arr);
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl; // Output should be: 0 0 0 0 1 1 1 1
  return 0;
}
