#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxDistance(vector<int> &arr) {

    int ans = 0;
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++) {
      int x = arr[i];

      if (mp.find(x) != mp.end()) {
        ans = max(ans, i - (mp.find(x)->second));
      }
      if (mp.find(x) == mp.end()) {
        mp[x] = i;
      }
    }
    return ans;
  }
};
int main() {
  Solution sol;
  vector<int> arr = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2};
  cout << sol.maxDistance(arr) << endl; // Example usage
  return 0;
}
