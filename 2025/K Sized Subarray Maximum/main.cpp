#include <deque>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> maxOfSubarrays(vector<int> &arr, int k) {
    if (k == 1) {
      return arr;
    }

    deque<int> dp;
    vector<int> result;
    for (int i = 0; i < arr.size(); i++) {
      while (!dp.empty() && dp.front() <= i - k) {
        dp.pop_front();
      }
      while (!dp.empty() && arr[dp.back()] < arr[i]) {
        dp.pop_back();
      }
      dp.push_back(i);
      if (i >= k - 1) {
        result.push_back(arr[dp.front()]);
      }
    }
    return result;
  };
};

int main() {
  Solution sol;
  vector<int> arr = {33, 38, 46, 24, 26, 6, 42, 28};
  int k = 2;
  vector<int> result = sol.maxOfSubarrays(arr, k);

  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
