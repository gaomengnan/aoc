#include "iostream"
#include "vector"
using namespace std;

void heapify(vector<int> &arr, int n, int i) {
  int lgv = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[lgv]) {
    lgv = l;
  }

  if (r < n && arr[r] > arr[lgv]) {
    lgv = r;
  }
  if (lgv != i) {
    swap(arr[i], arr[lgv]);
    heapify(arr, n, lgv);
  }
}

void heapSort(vector<int> &arr) {
  int n = arr.size();

  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }
  for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int main() {
  vector<int> arr = {9, 4, 3, 8, 10, 2, 5};

  heapSort(arr);

  for (int i = 0; i < arr.size(); ++i)
    cout << arr[i] << " ";
}
