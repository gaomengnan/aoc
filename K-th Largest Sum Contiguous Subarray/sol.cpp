#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// User function Template for C++

class Solution {
public:
  int kthLargest(vector<int> &arr, int k) {
    // code here
    priority_queue<int, vector<int>, greater<int>> pq; // 最小堆
    for (int i = 0; i < arr.size(); i++) {

      int cur_sum = 0;

      for (int j = i; j < arr.size(); j++) {
        cur_sum += arr[j];

        if (pq.size() < k) {
          pq.push(cur_sum);
        } else if (cur_sum > pq.top()) {
          pq.pop();
          pq.push(cur_sum);
        }
      }
    }

    return pq.top();
  }
};

int main() {
  Solution sol;
  vector<int> arr = {3, 1, 5, 12, 2, 11};
  int k = 3;
  cout << sol.kthLargest(arr, k) << endl; // Expected output: 5
  return 0;
}
