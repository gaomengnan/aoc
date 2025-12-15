#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void merge(vector<string> &arr, int l, int mid, int r) {
    vector<string> temp;
    int i = l;
    int j = mid + 1;
    while (i <= mid && j <= r) {
      if (arr[i].size() <= arr[j].size()) {
        temp.push_back(arr[i++]);
      } else {
        temp.push_back(arr[j++]);
      }
    }
    while (i <= mid)
      temp.push_back(arr[i++]);
    while (j <= r)
      temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++) {
      arr[l + k] = temp[k];
    }
  }

public:
  void merge_sort(vector<string> &arr, int l, int r) {
    if (l >= r)
      return;
    int mid = l + (r - l) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    merge(arr, l, mid, r);
  }

public:
  void sortByLength(vector<string> &arr) {
    vector<pair<string, int>> ms;
    merge_sort(arr, 0, arr.size() - 1);
  }
};

int main() {
  Solution sol;
  vector<string> arr = {"apple", "banana", "kiwi", "pear", "grape"};
  sol.sortByLength(arr);

  for (const string &s : arr) {
    cout << s << " ";
  }
  cout << endl;

  return 0;
}
