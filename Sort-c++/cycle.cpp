#include <iostream>
#include <vector>
using namespace std;

void cycleSort(vector<int> &arr, int n) {

  int writes = 0;

  for (int cycle_start = 0; cycle_start < n - 1; cycle_start++) {

    int item = arr[cycle_start];

    int pos = cycle_start;

    for (int j = cycle_start + 1; j < n; j++) {
      if (arr[j] < item) {
        pos++;
      }
    }
    if (pos == cycle_start) {
      continue;
    }

    // 重复
    while (item == arr[pos])
      pos++;

    if (pos != cycle_start) {
      swap(item, arr[pos]);

      writes++;
    }

    while (pos != cycle_start) {
      pos = cycle_start;
      for (int k = cycle_start + 1; k < n; k++) {
        if (arr[k] < item) {
          pos++;
        }
        while (item == arr[pos]) {
          pos++;
        }
        if (item != arr[pos]) {
          swap(item, arr[pos]);
        }
      }
    }
  }
  cout << "writes" << writes << endl;
}

int main() {
  vector<int> arr = {2, 8, 5, 4};
  cycleSort(arr, arr.size());

  for (int x : arr)
    cout << x << " ";
  return 0;
}
