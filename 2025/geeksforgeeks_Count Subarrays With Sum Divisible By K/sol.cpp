#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  // Function to count the number of subarrays with a sum that is divisible by K
  int subCount(vector<int> &arr, int k) {
    int n = arr.size();
    unordered_map<int, long long> mp;
    mp[0] = 1;
    long long win_sum = 0;
    long long count = 0;

    for (int i = 0; i < n; i++) {
      win_sum += arr[i];
      int rem = ((win_sum % k) + k) % k;
      if (mp.find(rem) != mp.end()) {
        count += mp[rem];
      }
      mp[rem]++;
    }

    return count;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {4, 5, 0, -2, -3, 1};
  int k = 5;
  cout << "Number of subarrays with sum divisible by " << k << ": "
       << sol.subCount(arr, k) << endl;
  return 0;
}
