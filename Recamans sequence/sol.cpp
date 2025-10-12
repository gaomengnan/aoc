#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <print>
using namespace std;

class Solution {
public:
  vector<int> recamanSequence(int n) {
    unordered_set<int> mpset;
    vector<int> res;
    res.push_back(0);
    mpset.insert(0);
    for (int i = 1; i < n; i++) {
      // 先当前val - 当前index
      int f = res[i-1] - i;

      if (f < 0 || mpset.find(f) != mpset.end()) {
        f = res[i-1] + i;
      }
      mpset.insert(f);
      res.push_back(f);
    }

    println("res is {}", res);

    return res;
  };
};

int main() {
  Solution sol;
  int n = 3;
  auto res = sol.recamanSequence(n);
  for (auto x : res) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
