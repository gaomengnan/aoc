#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> countDistinct(vector<int> &arr, int k) {
    int n = arr.size();
    unordered_map<int, int> mp;
    vector<int> ans;

    int l = 0;

    for (int i = 0; i < n; i++) {
      mp[arr[i]]++;
      while (i - l >= k) {
        mp[arr[l]]--;
        if (mp[arr[l]] == 0) {
          mp.erase(arr[l]);
        }
        l++;
      }

      if (i - l + 1 == k) {
        ans.push_back(mp.size());
      }
    }

    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {1, 1, 1, 1, 1};
  int k = 3;
  vector<int> result = sol.countDistinct(arr, k);
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
