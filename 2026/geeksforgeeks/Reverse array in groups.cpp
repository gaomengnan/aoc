/*
  Given an array arr[] of positive integers. Reverse every sub-array group of
  size k. Note: If at any instance, k is greater or equal to the array size,
  then reverse the entire array.
*/

#include <cstddef>
#include <vector>
using namespace std;

class Solution {
public:
  void reverseInGroups(vector<int> &arr, int k) {
    int n = arr.size();
    // code here
    for (int i = 0; i < n; i += k) {
      int left = i;
      int right = min(i + k - 1, n - 1);
      while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
      }
    }
    return;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {5, 6, 8, 9};
  int k = 5;
  sol.reverseInGroups(arr, k);
  return 0;
}

// 7-3 = 4
// 4 -3 = 1
// 7 -4 = 3

// 1 2 3 /  4 5 6 7 8
