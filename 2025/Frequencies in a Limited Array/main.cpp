#include <vector>
using namespace std;

class Solution {
public:
  // Function to count the frequency of all elements from 1 to N in the array.
  vector<int> frequencyCount(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      arr[i]--;
    }
    for (int i = 0; i < n; i++) {
      int idx = arr[i] % n;
      if (idx >= 0 && idx < n) {
        arr[idx] += n;
      }
    }
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
      result[i] = arr[i] / n;
    }
    return result;
  }
};

int main() {
  // Example usage
  Solution sol;
  vector<int> arr = {2, 3, 2, 3, 5};
  vector<int> freq = sol.frequencyCount(arr);
  // print
  for (int count : freq) {
    printf("%d ", count);
  }

  // freq should be {0, 2, 2, 0, 1}
  return 0;
}
