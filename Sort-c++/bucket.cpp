#include <iostream>
#include <vector>

using namespace std;

void insert_sort_1(vector<float> &buks) {

  for (int i = 1; i < buks.size(); ++i) {
    float key = buks[i];
    int j = i - 1;

    while (j >= 0 && buks[j] > key) {
      buks[j + 1] = buks[j];
      j--;
    }

    buks[j + 1] = key;
  }
}

void bucketSort(float arr[], int n) {
  // 创建一个空的桶
  vector<vector<float>> buckets(n);

  // 将数组元素分配到各个桶中
  for (int i = 0; i < n; ++i) {
    int pi = min(n - 1, int(arr[i] * n));
    buckets[pi].push_back(arr[i]);
  }
  // 对每个桶进行排序
  for (int i = 0; i < n; ++i) {
    insert_sort_1(buckets[i]);
  }
  // 将排序后的桶中的元素合并回原数组
  int index = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < buckets[i].size(); ++j) {
      arr[index++] = buckets[i][j];
    }
  }
}

void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isSorted(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    // Test case 1: Normal case
    float arr1[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    bucketSort(arr1, n1);
    cout << "Test Case 1: \n";
    printArray(arr1, n1);
    cout << (isSorted(arr1, n1) ? "PASS" : "FAIL") << endl;

    // Test case 2: Edge case with empty array
    float arr2[] = {};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    bucketSort(arr2, n2);
    cout << "Test Case 2: \n";
    printArray(arr2, n2);
    cout << (isSorted(arr2, n2) ? "PASS" : "FAIL") << endl;

    // Test case 3: All elements are the same
    float arr3[] = {0.5, 0.5, 0.5, 0.5, 0.5};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    bucketSort(arr3, n3);
    cout << "Test Case 3: \n";
    printArray(arr3, n3);
    cout << (isSorted(arr3, n3) ? "PASS" : "FAIL") << endl;

    // Test case 4: Single element
    float arr4[] = {0.3};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    bucketSort(arr4, n4);
    cout << "Test Case 4: \n";
    printArray(arr4, n4);
    cout << (isSorted(arr4, n4) ? "PASS" : "FAIL") << endl;

    return 0;
}
