#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  bool canPair(vector<int> &arr, int k) {
    int n = arr.size();
    if (n % 2 != 0) return false; // 必须能分成偶数对
    unordered_map<int, int> remCount;

    for (int num : arr) {
        int rem = ((num % k) + k) % k; // 处理负数
        remCount[rem]++;
    }
    for (int rem = 0; rem <= k/2; ++rem) {
        if (rem == 0) {
            if (remCount[rem] % 2 != 0) return false;
        } else if (k % 2 == 0 && rem == k/2) {
            if (remCount[rem] % 2 != 0) return false;
        } else {
            if (remCount[rem] != remCount[k - rem]) return false;
        }
    }
    return true;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {4,4,4};
  int k = 4;
  cout << (sol.canPair(arr, k) ? "true" : "false") << endl; // Output: true
  return 0;
}
