#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int mostFreqEle(vector<int> &arr) {
    int maxEle = 0;
    int maxCounter = 0;

    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++) {
      int x = arr[i];
      mp[x]++;
      if (mp[x] >= maxCounter) {
        if (mp[x] == maxCounter) {
          maxEle = max(maxEle, x);
        } else {
          maxEle = x;
        }
        maxCounter = mp[x];
      }
    }
    return maxEle;
  }
};
int main() {
  Solution sol;
  vector<int> arr = {1, 2, 3, 2, 4, 1, 2};
  int result = sol.mostFreqEle(arr);
  cout << "Most frequent element: " << result << endl;
  return 0;
}
