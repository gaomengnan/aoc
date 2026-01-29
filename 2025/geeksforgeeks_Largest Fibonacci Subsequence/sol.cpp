#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool isFibonacci(long long n) {
    return isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4);
  }

  bool isPerfectSquare(long long x) {
    long long s = sqrt(x);
    return s * s == x;
  }

  int fib(int n) {

    if (n == 0) {
      return 0;
    }

    if (n == 1) {
      return 1;
    }

    return fib(n - 1) + fib(n - 2);
  }

  vector<int> findFibSubset(vector<int> &arr) {
    int n = arr.size();
    vector<int> fibSubset;

    for (int i = 0; i < n; i++) {
      if (isFibonacci(arr[i])) {
        fibSubset.push_back(arr[i]);
      }
    }

    return fibSubset;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {1, 4, 3, 9, 10, 13};
  vector<int> result = sol.findFibSubset(arr);
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
