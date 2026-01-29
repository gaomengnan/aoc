#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> intersect(vector<int> &a, vector<int> &b) {
      unordered_map<int, int> mp;
    vector<int> ans(0);
      for (int i = 0; i < a.size(); i++) {
          mp[a[i]] ++;
      }

      for (int i = 0; i < b.size(); i++) {
        if (mp.find(b[i]) != mp.end()) {
          // mp[b[i]] --;
          // if (mp[b[i]] == 0) {
          // }
          mp.erase(b[i]);
          ans.push_back(b[i]);
        }
      }
      return ans;
  };
};
int main() {
  Solution sol;
  vector<int> a = {1, 2, 1, 3, 1};
  vector<int> b = {3, 1, 3, 4, 1};
  vector<int> result = sol.intersect(a, b);
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
