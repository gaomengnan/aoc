#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int maxElements(vector<int> &arr, int k) {
  int n = arr.size();
  unordered_map<int, int> mp;

  int h = 0;
  int prev = -1;
  int win_count = 0;
  int ans = 0;

  for (int i = 0; i < n; ++i) {
    // cout << i << endl;

    if (arr[i] != prev) {
      win_count++;
      prev = arr[i];
    }
    int fv = arr[h];

    if (win_count > k) {
      while (fv == arr[h]) {
        h++;
      }
      win_count--;
    }

    if (win_count == k) {
      ans = max(ans, i - h + 1);
    }
  }

  return ans;
}

// int main() { Solution sol; }
int main() {

  vector<int> arr = {1, 2, 2, 3, 1, 4};
  int k = 2;

  cout << maxElements(arr, k) << endl;

  return 0;
}
