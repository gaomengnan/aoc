#include <algorithm>
#include <cmath>
#include <iostream>
#include <print>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int lbs(int arr[], int n) {

  vector<int> mp(n);
  mp[0] = 0;
  int st = 1;
  int ed = -1;

  for (int i = 1; i < n; i++) {
    int check = arr[i] - arr[i - 1];
    // 递增
    if (check == 1) {
      mp[i] = st;
      mp[i - 1] = st;
      // 递减
    } else if (check == -1) {
      mp[i] = ed;
      mp[i - 1] = ed;
    } else {
      st++;
      ed--;
      mp[i] = 0;
    }
  }

  println("mp is {}", mp);

  int start = 0;
  int startIdx = 0;
  int ans = 0;

  for (int i = 0; i < mp.size(); i++) {
    if (start != mp[i]) {
      // 一开始是递增
      // 变成递减可以连续
      if (start <= 0 || (start > 0 && mp[i] > 0)) {
        start = mp[i];
        startIdx = i;
      }
      if (start > 0 && mp[i] < 0) {
        start = mp[i];
      }
    }
    ans = max(ans, i - startIdx);
  }
  println("start is {}, startIdx is {}, ans is {}", start, startIdx, ans);
  if (ans == 0) {
    return 0;
  }
  return ans + 1;
}
// 1  4  -3  1  1  1  -2  -1
//        ^
// -4 3  -1  -1 -1 2  1   1

int main() {
  int arr[] = {
      3, 2, 2, 3, 4, 5
  };
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Length of LBS is %d\n", lbs(arr, n));
  return 0;
}
// 0 0 {0 1 1 1 0 -1}
