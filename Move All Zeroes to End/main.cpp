#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void pushZerosToEnd(vector<int> &arr) {
    int n = arr.size();
    int nonZeroPos = 0;

    // Move non-zero elements forward
    for (int i = 0; i < n; i++) {
      if (arr[i] != 0) {
        arr[nonZeroPos++] = arr[i];
      }
    }

    // Fill remaining with zeros
    while (nonZeroPos < n) {
      arr[nonZeroPos++] = 0;
    }
  }
};

int main() {
  Solution sol;
  vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
  sol.pushZerosToEnd(arr);
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
