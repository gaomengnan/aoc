#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

vector<vector<int>> fourSum(vector<int> &arr, int target) {
    vector<vector<int>> res;
    unordered_map<int, vector<pair<int, int>>> mp;
    int n = arr.size();

    for (int i = 0; i < n-1; i++) {

        for (int j = i+1; j < n; j++) {

            int need = target - arr[i] - arr[j];
            if (mp.find(need) != mp.end()) {
                for (auto &p : mp[need]) {
                    int a = p.first, b = p.second;
                    // 防止索引重复
                    if (a != i && a != j && b != i && b != j) {
                        vector<int> quad = {a, b, i, j};
                        sort(quad.begin(), quad.end());
                        res.push_back(quad);
                    }
                }
            }

        }

        for (int k = 0; k < i; k++) {
            mp[arr[k] + arr[i]].push_back({k,i});
        }

    }
    return res;
}
int main() {
  vector<int> arr = {1, 5, 3, 1, 2, 10};
  int target = 20;
  vector<vector<int>> ans = fourSum(arr, target);
  for (auto v : ans) {
    for (auto x : v) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}
