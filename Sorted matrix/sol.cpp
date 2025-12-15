#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// User function Template for C++
class Solution {
public:
  vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
    vector<int> flat;
    for (auto &row : Mat) {
      for (int x : row) {
        flat.push_back(x);
      }
    }

    sort(flat.begin(), flat.end());

    for (int i = 0; i < flat.size(); i++) {
      Mat[i / N][i % N] = flat[i];
    }


    return Mat;
  }
};
int main() {
  Solution sol;
  vector<vector<int>> mat{{5, 4, 7}, {1, 3, 8}, {2, 9, 6}};

  mat = sol.sortedMatrix(3, mat);

  for (auto &row : mat) {
    for (int x : row) {
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}
