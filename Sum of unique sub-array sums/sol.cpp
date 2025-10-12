#include <iostream>
#include <print>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

int findSubarraySum(vector<int> &arr) {
  int n = arr.size();
  vector<int> mp;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += arr[j];
      mp.push_back(sum);
    }
  }
  // println("mp is {}", mp);

sort(mp.begin(), mp.end());

int m = mp.size();

if (m == 1)
  return mp[0];
int total = 0;
if (mp[0] != mp[1]) {
  total += mp[0];
}

for (int i = 1; i < m - 1; i++) {
  if (mp[i] != mp[i + 1] && mp[i] != mp[i - 1]) {
    total += mp[i];
  }
}
if (mp[m-1] != mp[m-2]) {
  total += mp[m-1];
}
// println("total is {}", total);

return total;
}

int main() {
vector<int> arr = {3, 2, 3, 1, 4};
cout << findSubarraySum(arr);
return 0;
}
