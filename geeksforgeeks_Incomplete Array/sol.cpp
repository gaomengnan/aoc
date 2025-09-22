#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  int countElements(vector<int> &arr) {
    if (arr.size() == 1) {
      return 0;
    }
    unordered_set<int> mp;
    sort(arr.begin(), arr.end());

    int low = arr[0];
    int high = arr[arr.size() - 1];

    int dif = high - low - 1;
    mp.insert(arr[0]);
    mp.insert(arr[arr.size() - 1]);

    for (int i = 1; i < arr.size() - 1; i++) {
      if (mp.find(arr[i]) == mp.end()) {
        dif--;
      }
      mp.insert(arr[i]);
    }
    return dif;
  }
};
int main() {
  Solution sol;
  vector<int> arr = {10, 5, 5, 9, 4, 7, 10, 5};
  int result = sol.countElements(arr);
  cout << result << endl; // Output the result
  return 0;
}
