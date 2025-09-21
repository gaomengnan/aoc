#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int kadane(vector<int> &mat) {

    int cur = 0;
    int best = 0;

    for (int i = 0; i < mat.size(); i++) {
      cur += mat[i];
      if (cur < 0) {
        cur = 0;
      }
      best = max(best, cur);
    }
    return best;
  };

  int maxRectSum(vector<vector<int>> &mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    int maxSum = INT_MIN;

    // Initialize a temporary array to store row-wise
    // sums between left and right boundaries
    vector<int> temp(rows);

    // Check for all possible left and right boundaries
    for (int left = 0; left < cols; left++) {

      // Reset the temporary array for each new left boundary
      for (int i = 0; i < rows; i++)
        temp[i] = 0;

      for (int right = left; right < cols; right++) {

        // Update the temporary array with the current
        // column's values
        for (int row = 0; row < rows; row++) {
          temp[row] += mat[row][right];
        }

        // Find the maximum sum of the subarray for the
        // current column boundaries
        int sum = kadane(temp);

        // Update the maximum sum found so far
        maxSum = max(maxSum, sum);
      }
    }

    return maxSum;
  }
};

int main() {
  Solution sol;
  std::vector<std::vector<int>> mat = {{1, 2, -1, -4, -20},
                                       {-8, -3, 4, 2, 1},
                                       {3, 8, 10, 1, 3},
                                       {-4, -1, 1, 7, -6}};
  std::cout << "Maximum rectangular sum: " << sol.maxRectSum(mat) << std::endl;
  return 0;
}
