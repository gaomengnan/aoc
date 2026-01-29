#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void print() {}

class Solution {
public:
  // Complete this function
  // Function to check whether there is a subarray present with 0-sum or not.
  bool subArrayExists(vector<int> &arr) {
    unordered_map<int, int> mp;
    mp[0] = -1;
    int win_sum = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
      if (arr[i] == 0) {
        return true;
      }

      win_sum += arr[i];
      if (mp.find(win_sum - 0) != mp.end()) {
        return true;
      }
      if (mp.find(win_sum) == mp.end()) {
        mp[win_sum] = i;
      }
    }
    return false;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {3, -3, -4, -2, 10};
  if (sol.subArrayExists(arr)) {
    cout << "Found a subarray with 0 sum" << endl;
  } else {
    cout << "No Such Sub Array Exists!" << endl;
  }
  return 0;
}
// 4, 2, -3, 1, 6
// 4  6  3   4
