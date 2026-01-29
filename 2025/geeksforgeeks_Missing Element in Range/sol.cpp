#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {

public:
  vector<int> missinRange(vector<int> &arr, int low, int high) {
    vector<int> ans;
    unordered_set<int> mp;

    for (int i = 0; i < arr.size(); i++) {
      mp.insert(arr[i]);
    }

    for (int i = low; i <= high; i++) {
      if (mp.find(i) == mp.end()) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
int main() {
  Solution sol;
  vector<int> arr = {1, 2, 3, 5, 7, 10};
  int low = 1;
  int high = 10;
  vector<int> result = sol.missinRange(arr, low, high);
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
