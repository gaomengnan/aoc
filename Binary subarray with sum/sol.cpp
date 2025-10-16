#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int numberOfSubarrays(vector<int> &arr, int target) {
    int n = arr.size();
    unordered_map<int, int> mp;
    int win_sum = 0;
    int left = 0;
    int ans = 0;

    for (int r = 0; r < n; ++r) {
      win_sum += arr[r];
      while (win_sum > target) {
        win_sum -= arr[left];
        left++;
      }

      if (win_sum == target) {
        ans++;
        int left2 = left;
        while(win_sum - arr[left2] == target) {
            ans++;
            left2++;
        }
      }
    }

    return ans;
  }
};

int main() {
  vector<int> arr = {1, 1, 0, 1, 1};
  int target = 2;

  Solution sol;
  cout << sol.numberOfSubarrays(arr, target) << endl;

  return 0;
}
