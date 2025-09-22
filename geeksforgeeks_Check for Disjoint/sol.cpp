#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool areDisjoint(vector<int> &a, vector<int> &b) {

    unordered_set<int> mp;

    for (int i = 0; i < a.size(); i++) {
      mp.insert(a[i]);
    }

    for (int i = 0; i < b.size(); i++) {
      if (mp.find(b[i]) != mp.end()) {
        return false;
      }
    }

    return true;
  }
};

int main() {
  Solution sol;
  vector<int> a = {12, 34, 11, 9, 3};
  vector<int> b = {7, 2, 1, 5};
  cout << (sol.areDisjoint(a, b) ? "Disjoint" : "Not Disjoint") << endl;
  return 0;
}
