#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int maxLength(vector<int> &arr) {
    int ans = 0;
    unordered_map<int, int> mp;

    int pre_sum = 0;

    for (int i = 0; i < arr.size(); i++) {
      pre_sum += arr[i];
      int df = 0 - pre_sum;
      if (df == 0) {
        ans = max(ans, i + 1);
      }

      if (mp.find(df) != mp.end()) {
        ans = max(ans, i - mp.find(df)->second);
      }

      if (mp.find(df) == mp.end()) {
        mp[df] = i;
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {2, 10, 4};
  cout << sol.maxLength(arr) << endl; // Output the result
  return 0;
}
// -1 -1 3  0 -1  -1
