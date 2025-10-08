#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int countSum(vector<int> &arr, int target) {
    unordered_map<int, int> mp;
    int n = arr.size();

    sort(arr.begin(), arr.end());

    int ans = 0;

    // 1 1 2 3 5 10

    for (int i = 0; i < n - 3; i++) {
      for (int j = i+1; j < n - 2; j++) {
        int twoSm = arr[i] + arr[j];
        // int leftVal = target - twoSm;
        int x = j + 1;
        int y = n - 1;

        // cout << i << j << endl;

        while (x < y) {
          // cout << x << y << endl;


          int m1 = arr[x];
          int m2 = arr[y];
          int total = twoSm + m1 + m2;
          // cout << total << " total" << endl;
          if (total == target) {
            if (m1 == m2) {
              // cout << "y" << y << "x" << x << endl;
              ans += (y - x + 1) * (y-x) / 2;
              break;
            }

            int x1 = x;
            int y1 = y;

            while (m1 == arr[x1]) {
              x1++;
            }

            while (m2 == arr[y1]) {
              y1--;
            }

            // cout << x1 << y1 <<endl;
            ans += (x1-x) * (y-y1);
            x = x1;
            y = y1;

          }else if (total > target) {
            y --;
          }else{
            x ++;
          }
        }
      }
    }
    return ans;
  }
};
// 2 + 1
// 1
// //

int main() {
  Solution sol;
  vector<int> arr = {1, 1, 1, 1, 2, 3,3,3};
  cout << sol.countSum(arr, 6) << endl;
}
