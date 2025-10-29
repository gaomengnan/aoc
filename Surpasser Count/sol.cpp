#include <iostream>
#include <print>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {

template<typename T, typename U, typename Compare = std::less<std::pair<T, U>>>
std::multiset<std::pair<T, U>, Compare> extract_less_than_copy(
    const std::multiset<std::pair<T, U>, Compare>& src,
    T x)
{
    // lower_bound: 第一个 >= {x, ...} 的位置
    auto it = src.lower_bound({x, std::numeric_limits<U>::lowest()});

    // 构造新容器：从 begin 到 it（即所有 first < x）
    return std::multiset<std::pair<T, U>, Compare>(src.begin(), it);
}
public:
  vector<int> findSurpasser(vector<int> &arr) {
    int n = arr.size();
    multiset<pair<int, int>> mp;
    vector<int> res(n, 0);

    for (int i = 0; i < n; i++) {
      auto ext = extract_less_than_copy(mp, arr[i]);
      for (const auto &p : ext) {
          res[p.second] += 1;
      }
      // print("ext is {}", ext);
      mp.insert({arr[i], i});
    }
    return res;
  }
};

int main() {
  // 1 2 3 5 7 8
  Solution sol;
  vector<int> a = {4,5,1};
  // 3 0 0 0
  vector<int> res = sol.findSurpasser(a);
  // print("res is {}", res);
  return 0;
}
