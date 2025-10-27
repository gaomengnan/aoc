#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int countTriangles(vector<int> &arr) {
    // code here
    int n = arr.size();
    int ans = 0;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++) {
      for (int j = i + 1; j < n - 1; j++) {
        int x = arr[i] + arr[j];
        int right = n;
        int left = j + 1;
        while (left <= right) {
          int mid = left + (right - left) / 2;

          // 找出第一个大于x 的值后面就是满足条件的值
          if (x <= arr[mid]) {
            // 查找左边是否有小于 x 的数字
            right = mid - 1;

          } else {
            // 查找左边哪个开始大于x
            left = mid + 1;
          }
        }
        if (right > n-1) {
          right = n-1;
        }
        ans += right - j;
      }
    }

    return ans;
  }
};

int main() {
  Solution sol;
  //  3 4 6 7
  vector<int> arr = {10, 21, 22, 100, 101, 200, 300};
  cout << sol.countTriangles(arr) << endl; // Output: 4
  return 0;
}
