#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool isIntersect(vector<vector<int>> intervals) {
    sort(intervals.begin(), intervals.end());

    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] <= intervals[i - 1][1]) {
        return true;
      }
    }
    return false;
  }
};
int main() {
  Solution sol;
  vector<vector<int>> intervals = {{1, 2}, {2, 4}, {7, 8}, {4,5}};
  if (sol.isIntersect(intervals)) {
    cout << "Intervals intersect" << endl;
  } else {
    cout << "Intervals do not intersect" << endl;
  }
  return 0;
}
