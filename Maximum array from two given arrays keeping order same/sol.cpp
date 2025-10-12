#include <algorithm>
#include <print>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;


vector<int> maximizeTheFirstArray(vector<int> &a, vector<int> &b) {
  vector<int> res;
  unordered_map<int, int> mps;
  // 排序
  vector<int> a1 = a;
  vector<int> b1 = b;

  sort(a1.begin(), a1.end(), greater<int>());
  sort(b1.begin(), b1.end(), greater<int>());

  int i = 0;
  int j = 0;

  while (true) {
    if (a1[i] >= b1[j]) {
      mps[a1[i]]++;
      if (mps.size() > a.size()) {
        mps.erase(a1[i]);
        break;
      }

      i++;
    } else {
      mps[b1[j]]++;
      if (mps.size() > a.size()) {
        mps.erase(b1[j]);
        break;
      }

      j++;
    }
  }
  for (int i = 0; i < a.size(); i++) {
    if (mps.find(a[i]) != mps.end()) {
      res.push_back(a[i]);
    }
  }

  for (int i = 0; i < b.size(); i++) {
    if (mps.find(b[i]) != mps.end() && mps[b[i]] == 1) {
      res.push_back(b[i]);
    }
  }

  println("mps is {}", mps);
  println("a is {}", a1);
  println("b is {}", b1);
  println("res is {}", res);

  return res;
}
int main() {
  vector<int> a = {6, 7, 5, 3};
  vector<int> b = {5, 6, 2, 9};
  vector<int> res = maximizeTheFirstArray(a, b);
  println("res is {}", res);
  return 0;
}
