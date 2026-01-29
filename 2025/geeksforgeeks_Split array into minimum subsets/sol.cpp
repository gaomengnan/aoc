#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// User function Template for C++
class Solution {
public:
  int minSubsets(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int ans = 0;

    for (int i = 0; i < arr.size()-1; i++) {
      if (arr[i + 1] - arr[i] > 1) {
        ans++;
      }
    }
    return ans + 1;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {1, 2, 3, 4, 5, 7};
  cout << sol.minSubsets(arr) << endl;
  return 0;
}
