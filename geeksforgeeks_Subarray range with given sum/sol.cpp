#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int subArraySum(vector<int> &arr, int tar) {
    unordered_map<int, int> mp;

    int pre_sum = 0;
    int ans = 0;

    for (int i = 0; i < arr.size(); i++) {
      int x = arr[i];
      pre_sum += x;
      int df =  pre_sum - tar;
      if (pre_sum == tar) {
        ans += 1;
      }

      if (mp.find(df) != mp.end()) {
        ans += mp.find(df)->second;
      }
      mp[pre_sum]++;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {10, 2, -2, -20, 10};
  int tar = -10;
  cout << sol.subArraySum(arr, tar) << endl; // Output: 3
  return 0;
}
// 10 12 10 -10 0
//
