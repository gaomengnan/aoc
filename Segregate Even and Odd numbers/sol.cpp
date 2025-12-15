#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  void segregateEvenOdd(vector<int> &arr) {

    int lo = 0;
    int hi = arr.size() - 1;

    while (lo < hi) {

      while (lo < hi && arr[lo] % 2 == 0) {
        lo++;
      }
      while (lo < hi && arr[hi] % 2 == 1) {
        hi--;
      }

      if (lo < hi) {
        swap(arr[lo], arr[hi]);
        lo++;
        hi--;
      }
    }
  }
};

int main() {
  Solution sol;
  vector<int> arr = {10, 22, 4, 6};
  sol.segregateEvenOdd(arr);

  for (int num : arr) {
    cout << num << " ";
  }

  return 0;
}
