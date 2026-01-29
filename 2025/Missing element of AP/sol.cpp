#include <algorithm>
#include <iostream>
#include <print>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// User function template for C++

class Solution {
public:
  int findMissing(vector<int> &arr) {
    int n = arr.size();
    // int k_sum = (arr[0] + arr[n - 1]) * n / 2;
    long long  total = 0;
    unordered_map<int, int> mp;

    for (int i = 1; i < n; ++i) {
      mp[arr[i] - arr[i - 1]]++;
    }
    long long first = arr[0];
    long long second =  arr[1];
    long long last = arr[n-1];

    //  说明这个是个完整de等差
    if (mp.size() == 1) {
      return last + (second - first);
    }

    // print("k sum is {} \n", mp);
    for (int i = 0; i < n; ++i) {
      total += arr[i];
    }

    long long  z_sum = (first + last) * (n + 1) / 2;

    return z_sum - total;
  }
};
int main() {
  Solution sol;
  // $S_n = \frac{n}{2}(a_1 + a_n)$
  // 65 - 52

  vector<int> arr = {0,1,2,3,4,5,7,8};
  int missing = sol.findMissing(arr);
  cout << "Missing number is: " << missing << endl;
  return 0;
}
