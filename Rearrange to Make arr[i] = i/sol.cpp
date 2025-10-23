#include <algorithm>
#include <print>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
  void modifyArray(vector<int> &arr) {
    int n = arr.size();
    unordered_set<int> freq;

    for (int i = 0; i < n; i++) {
        freq.insert(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        if (freq.find(i) != freq.end()) {
            arr[i] = i;
        }else{
            arr[i] = -1;
        }
    }
    // sort(arr.begin(), arr.end());
    // println("arr sorted is {}", arr);
    return;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
  sol.modifyArray(arr);
  println("arr res Is {}", arr); // Output should be a sorted array: [1, 2, 3, 5, 8]
  return 0;
}
