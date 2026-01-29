#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool checkDuplicatesWithinK(vector<int> &arr, int k) {
    unordered_map<int, int> mp;
    int n  = arr.size();

    for (int i = 0; i < n; i++) {
      if (mp.find(arr[i]) != mp.end()) {
        int distance = i - (mp.find(arr[i])->second);
        if (distance <=k) {
          return true;
        }
      }
      if (mp.find(arr[i]) == mp.end()) {
        mp[arr[i]] = i;
      }
    }
    return false;
  };
};
