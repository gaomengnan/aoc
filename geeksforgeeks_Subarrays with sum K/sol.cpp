#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int cntSubarrays(vector<int> &arr, int k) {
    int n = arr.size();
    unordered_map<int, int> mp;
    mp[0] = 1;
    int win_sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
      win_sum += arr[i];
      int diffv = win_sum - k;
      if (mp.find(diffv) != mp.end()) {
        count += mp[diffv];
      }
      mp[win_sum]++;
    }

    return count;
  }
};
int main() {
  Solution sol;
  vector<int> arr = {10, 2, -2, -20, 10};
  int k = 10;
  cout << sol.cntSubarrays(arr, k) << endl; // Output: 3
  return 0;
}
