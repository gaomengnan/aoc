#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  void sortInWave(vector<int> &arr) {

    for (int i = 0; i < arr.size(); i++) {
      if ((i + 1) % 2 == 0)
        swap(arr[i], arr[i - 1]);
    }
  }
};

int main() {
  Solution sol;

  vector<int> arr = {1};
  sol.sortInWave(arr);
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  return 0;
}
