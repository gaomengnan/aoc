#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
void minRange(vector<int> &arr, int n, int k) {
  unordered_map<int, int> mp;

  int l = 0;
  int ans = 0;
  int min_len = INT_MAX;
  vector<int> pairs(2);

  for (int i = 0; i < arr.size(); i++) {
    mp[arr[i]]++;

    while (mp.size() > k) {
      mp[arr[l]]--;

      if (mp[arr[l]] == 0) {
        mp.erase(arr[l]);
      }
      l++;
    }

    if (mp.size() == k) {
      // cout << l << i << endl;
      while (arr[l] == arr[l + 1]) {
        mp[arr[l]]--;
        l++;
      }
      // cout << l << i << endl;
      if (i - l < min_len) {
        min_len = i - l;
        pairs = {l, i};
      }
    }
  }

  cout << pairs[0] << pairs[1] << endl;
}
// Driver code for above function.
int main() {
  vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5};
  int n = arr.size();
  int k = 3;
  minRange(arr, n, k);
  return 0;
}
