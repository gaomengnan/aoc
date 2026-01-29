#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int minRemove(vector<int> &arr1, vector<int> &arr2) {
    unordered_map<int, int> mp;
    int ans = 0;

    for (int i = 0; i < arr1.size(); i++) {
      mp[arr1[i]]++;
    }

    for (int i = 0; i < arr2.size(); i++) {
      if (mp.find(arr2[i]) != mp.end()) {
        mp[arr2[i]]--;
        if (mp[arr2[i]] == 0) {
          mp.erase(arr2[i]);
        }
        ans++;
      }
    }

    return ans;
  }
};
int main() {
  Solution sol;
  vector<int> a = {8, 8, 9, 10, 2, 2, 5, 5, 8, 7};
  vector<int> b = {10, 6, 9, 3, 3, 2, 10, 9, 9, 9};
  cout << sol.minRemove(a, b) << endl;
  return 0;
}
