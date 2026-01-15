#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> nextLargerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n, -1);

    stack<int> stk;

    for (int i = n - 1; i >= 0; --i) {
      while (!stk.empty() && arr[stk.top()] <= arr[i]) {
        stk.pop();
      }

      if (!stk.empty()) {
        ans[i] = arr[stk.top()];
      }
      stk.push(i);
    }

    return ans;
  }
};

// 輔助函數：印出 vector
void printVector(const vector<int> &vec) {
  cout << "[";
  for (size_t i = 0; i < vec.size(); ++i) {
    cout << vec[i];
    if (i < vec.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl;
}

int main() {
  Solution sol;

  // 測試案例 1 - 經典例子
  vector<int> arr1 = {4, 5, 2, 25};
  cout << "Input:  [4, 5, 2, 25]\n";
  cout << "Output: ";
  printVector(sol.nextLargerElement(arr1));
  // 預期: [5, 25, 25, -1]

  // 測試案例 2 - 遞減序列（全部 -1）
  vector<int> arr2 = {13, 7, 6, 5, 3};
  cout << "\nInput:  [13, 7, 6, 5, 3]\n";
  cout << "Output: ";
  printVector(sol.nextLargerElement(arr2));
  // 預期: [-1, -1, -1, -1, -1]

  // 測試案例 3 - 遞增序列
  vector<int> arr3 = {1, 2, 3, 4, 5};
  cout << "\nInput:  [1, 2, 3, 4, 5]\n";
  cout << "Output: ";
  printVector(sol.nextLargerElement(arr3));
  // 預期: [2, 3, 4, 5, -1]

  // 測試案例 4 - 有重複元素
  vector<int> arr4 = {1, 3, 2, 4, 3, 2, 5};
  cout << "\nInput:  [1, 3, 2, 4, 3, 2, 5]\n";
  cout << "Output: ";
  printVector(sol.nextLargerElement(arr4));
  // 預期: [3, 4, 4, 5, 5, 5, -1]

  // 測試案例 5 - 單元素
  vector<int> arr5 = {10};
  cout << "\nInput:  [10]\n";
  cout << "Output: ";
  printVector(sol.nextLargerElement(arr5));
  // 預期: [-1]

  // 測試案例 6 - 空陣列
  vector<int> arr6 = {};
  cout << "\nInput:  []\n";
  cout << "Output: ";
  printVector(sol.nextLargerElement(arr6));
  // 預期: [] （空）

  return 0;
}
