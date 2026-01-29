#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int zeroSumSubmat(vector<vector<int>> &mat) {
    return 0;
    // Code Here
  }
};

int main() {
  Solution sol;
  std::vector<std::vector<int>> mat = {{1, 2, -3}, {4, -4, 6}, {-1, -2, 3}};
  std::cout << "Number of zero-sum submatrices: " << sol.zeroSumSubmat(mat)
            << std::endl;
  return 0;
}
