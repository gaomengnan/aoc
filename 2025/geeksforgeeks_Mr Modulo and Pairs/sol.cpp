#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int countPairs(vector<int> &arr, int k) {
    int maxVal = *max_element(arr.begin(), arr.end());
    int n = arr.size();

    unordered_set<int> st(arr.begin(), arr.end());
    int count = 0;

    for (int j = 0; j < n; j++) {
      int divisor = arr[j];
      if (divisor <= k) continue; // 必须保证 k < divisor

      for (int m = 0; m <= (maxVal - k) / divisor; m++) {
        int candidate = m * divisor + k;
        if (st.find(candidate) != st.end() && candidate != divisor) {
          count++;
          cout << candidate << " % " << divisor << " = " << k << endl;
        }
      }
    }

    return count;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {2, 3, 5, 4, 7};
  int k = 3;
  int result = sol.countPairs(arr, k);
  cout << "Total pairs = " << result << endl;
  return 0;
}
