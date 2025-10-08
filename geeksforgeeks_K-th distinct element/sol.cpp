#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int KthDistinct(vector<int> nums, int k) {
    unordered_map<int, int> mp;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      mp[nums[i]]++;
    }

    for (int i = 0; i < n; i++) {
      if (mp[nums[i]] == 1) {
        k--;
        if (k == 0) {
          return nums[i];
        }
      }
    }

    return -1;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 2, 50, 10, 20, 2};
  int k = 3;
  cout << sol.KthDistinct(nums, k) << endl; // Example usage
  return 0;
}
