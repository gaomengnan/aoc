#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int countSum(vector<int> &arr, int target) {

    int n = arr.size();
    unordered_map<int, int> mp;

    for (int i = 0; i < n - 3; i++) {

      for (int j = 0; j < n - 2; j++) {
          int need = target - arr[i] - arr[j];

          if (mp.find(need) != mp.end()) {
              ans += mp.find(need) -> second;
          }
      }

      for (int k = 0; k < i; k++) {
          mp[arr[k] + arr[i]] ++;
      }

    }

    return ans;
  }
};
// 2 + 1
// 1
// //

int main() {
  Solution sol;
  vector<int> arr = {1, 1, 1, 1, 2, 3, 3, 3};
  cout << sol.countSum(arr, 6) << endl;
}
