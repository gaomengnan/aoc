#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  // Function to find all elements in array that appear more than n/k times.
  int countOccurence(vector<int> &arr, int k) {

    int times = arr.size() / k;
    int ans = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++) {
      mp[arr[i]]++;
    }
    for (auto it : mp) {
      if (it.second > times) {
        ans++;
      }
    }

    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {2, 3, 3, 2};
  int k = 4;
  cout << sol.countOccurence(arr, k) << endl; // Output: 2
  return 0;
}
