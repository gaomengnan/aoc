#include <algorithm>
#include <iostream>
#include <print>
#include <queue>
#include <vector>
using namespace std;

struct Compare {
  int x;
  Compare(int target) : x(target) {}
  bool operator()(int a, int b) {
    int distA = abs(a - x);
    int distB = abs(b - x);
    if (distA != distB)
      return distA > distB; // 距离大的排前面（小顶堆）
    return a < b;           // 距离相等，值小的排前面
  }
};

class Solution {
public:
  vector<int> printKClosest(vector<int> arr, int k, int x) {
    priority_queue<int, vector<int>, Compare> q{Compare(x)};

    for (int num : arr) {
      if (num == x)
        continue; // 正确排除 x
      // print("num is {} \n", num);
      q.push(num);
      // print("queue num {} \n", q);
      // if (q.size() > k) {
      //   q.pop(); // 弹出最不接近的（堆顶）
      // }
      // print("poped queue is {} \n", q);
    }

    vector<int> result;
    while (!q.empty() && result.size() < k) {
      result.push_back(q.top());
      q.pop();
    }
    // print("result is {}", result);
    // reverse(result.begin(), result.end()); // 堆顶是最远的 → 反转为从近到远
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
  int k = 4, x = 35;
  vector<int> result = sol.printKClosest(arr, k, x);
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
