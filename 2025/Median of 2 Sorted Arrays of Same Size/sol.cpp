#include <algorithm>
#include <iostream>
#include <print>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  double medianOf2(vector<int> &a, vector<int> &b) {
    // int n = a.size();
    int x = 0;
    int y = 0;
    vector<int> merged;
    while (x < a.size() && y < b.size()) {
      if (a[x] < b[y]) {
        merged.push_back(a[x]);
        x++;
      } else {
        merged.push_back(b[y]);
        y++;
      }
    }
    cout << "x:" << x << " y:" << y << endl;
    while (x < a.size()) {
      merged.push_back(a[x]);
      x++;
    }

    while (y < b.size()) {
        merged.push_back(b[y]);
        y++;
    }
    print("merged:", merged);
    int n = merged.size();
    if (n % 2 == 1) {
        return merged[n / 2];
    } else {
        return (merged[n / 2 - 1] + merged[n / 2])
                / 2.0;
    }
  }
};

int main() {
  Solution sol;
  vector<int> a = {-5, 3, 6, 12, 15};
  vector<int> b = {-12, -10, -6, -3, 4};
  cout << sol.medianOf2(a, b) << endl; // 2.0

  a = {2, 3, 5, 7};
  b = {10, 12, 14, 16};
  cout << sol.medianOf2(a, b) << endl; // 2.5

  return 0;
}
