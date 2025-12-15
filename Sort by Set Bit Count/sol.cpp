#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {

public:
  int to_binary(int n) {
    std::bitset<32> bs(n); // 假设 32 位整数
    return bs.count();     // 返回二进制表示中 1 的数量
  }

public:
  void sortBySetBitCount(int arr[], int n) {
    std::vector<int> vec(arr, arr + n);
    sort(vec.begin(), vec.end(),
         [this](int a, int b) { return to_binary(a) > to_binary(b); });

    for (int i = 0; i < n; i++) {
      arr[i] = vec[i];
    }

    return;
  }
};

int main() {
  Solution sol;
  int arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
  int n = sizeof(arr) / sizeof(arr[0]);
  sol.sortBySetBitCount(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
