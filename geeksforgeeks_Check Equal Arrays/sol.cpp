#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool checkEqual(vector<int> &a, vector<int> &b) {
    unordered_map<int, int> mp;

    for (int i = 0; i < a.size(); i++) {
      mp[a[i]]++;
    }

    for (int i = 0; i < b.size(); i++) {

      if (mp.find(b[i]) == mp.end()) {
        return false;
      }
      mp[b[i]]--;
      if (mp[b[i]] == 0) {
        mp.erase(b[i]);
      }
    }
    return true;
  }
};

int main() {
  Solution sol;
  vector<int> a = {1, 2, 3};
  vector<int> b = {1, 2, 2};
  cout << sol.checkEqual(a, b) << endl; // Output: 1 (true)
  return 0;
}
