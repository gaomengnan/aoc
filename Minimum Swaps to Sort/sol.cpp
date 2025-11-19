#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int minSwaps(vector<int> &arr) {
    int n = arr.size();
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
      v[i] = {arr[i], i};
    sort(v.begin(), v.end());
    vector<bool> visited(n, false);
    int ans = 0;

    for (int i = 0; i < n; i++) {
      if (visited[i] || v[i].second == i)
        continue;
      int cycle_size = 0;
      int j = i;
      while (!visited[j]) {
        visited[j] = true;
        j = v[j].second;
        cycle_size++;
      }
      if (cycle_size > 1)
        ans += (cycle_size - 1);
    }
    return ans;
  }
};

int main() {
  Solution solution;
  vector<int> arr = {2, 8, 5, 4};
  int times = solution.minSwaps(arr);
  cout << "Minimum number of swaps required to sort the array: " << times
       << endl;
}
