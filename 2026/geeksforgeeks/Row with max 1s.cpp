/*
  You are given a 2D binary array arr[][] consisting of only 1s and 0s. Each row
  of the array is sorted in non-decreasing order. Your task is to find and
  return the index of the first row that contains the maximum number of 1s. If
  no such row exists, return -1. Note:

  The array follows 0-based indexing.
  The number of rows and columns in the array are denoted by n and m
  respectively.
*/
#include <vector>
using namespace std;

// User function template for C++
class Solution {
public:
  int rowWithMax1s(vector<vector<int>> &arr) {
    int maxRow = -1; // 用来记录拥有最多1的行号
    int maxCount = 0; // 最大1的数量
    int n = arr.size(); // 行的数量
    int m = arr[0].size(); // 列的数量

    for (int i = 0; i < n; i++) {
      // 使用二分查找该行第一个1的位置
      int low = 0, high = m - 1, firstOneIndex = m;
      while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[i][mid] == 1) {
          firstOneIndex = mid; // 向左查找
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }

      // 计算1的个数
      int count = m - firstOneIndex;
      if (count > maxCount) { // 更新最大计数和行号
        maxCount = count;
        maxRow = i;
      }
    }

    return maxRow;
  }
};

int main() { return 0; }
