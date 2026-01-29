#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution {
public:
  void heapify(vector<int> &arr, int n, int i) {
    int lgv = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[lgv]) {
      lgv = l;
    }
    if (r < n && arr[r] > arr[lgv]) {
      lgv = r;
    }

    if (lgv != i) {
      swap(arr[i], arr[lgv]);
      heapify(arr, n, lgv);
    }
  }
  // Function to sort an array using Heap Sort.
  void heapSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
      heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; --i) {
      swap(arr[0], arr[i]);
      heapify(arr, i, 0);
    }
  }
};

int main() {
  Solution sol;
  vector<int> arr = {12, 11, 13, 5, 6, 7};
  sol.heapSort(arr);
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
