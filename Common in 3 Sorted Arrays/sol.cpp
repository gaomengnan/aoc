#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  // Function to find common elements in three arrays.
  vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                             vector<int> &arr3) {

    unordered_set<int> res1;
    vector<int> res;
    int i = 0;
    int j = 0;

    while (i < arr1.size() && j < arr2.size()) {
      if (arr1[i] == arr2[j]) {
        res1.insert(arr1[i]);
        i++;
        j++;
      } else if (arr1[i] < arr2[j]) {
        i++;
      } else {
        j++;
      }
    }

    int z = 0;

    while (z < arr3.size()) {
      if (res1.find(arr3[z]) != res1.end()) {
        res.push_back(arr3[z]);
        res1.erase(arr3[z]);
      }
      z++;
    }
    return res;
  }
};
int main() {
  // Sample Input
  vector<int> arr1 = {1, 5, 10, 20, 40, 80};
  vector<int> arr2 = {6, 7, 20, 80, 100};
  vector<int> arr3 = {3, 4, 15, 20, 30, 70, 80, 120};
  Solution sol;

  vector<int> common = sol.commonElements(arr1, arr2, arr3);
  if (common.size() == 0)
    cout << -1;
  for (int i = 0; i < common.size(); i++) {
    cout << common[i] << " ";
  }

  return 0;
}
