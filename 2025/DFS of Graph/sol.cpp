#include <functional>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> dfs(vector<vector<int>> &adj) {
    // Code here
    // int n = adj.size();

    //  0 : 2 3 1
    // 1 : 0
    // 2: 0 4
    // 3: 0
    // 4 : 2
    vector<int> res;
    set<int> seen;
    // unordered_map<int, unordered_map<int, bool>> visited;

    function<void(int)> gdfs = [&](int x) {
      vector<int> arr = adj[x];

      for (int i = 0; i < arr.size(); ++i) {
        int current = adj[x][i];
        if (seen.find(current) == seen.end()) {
          res.push_back(current);
          seen.insert(current);
          gdfs(current);
        }
      }
    };
    // visited[0][0] = true;
    seen.insert(0);
    res.push_back(0);

    gdfs(0);
    return res;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> adj = {
      {1, 2}, {0, 2}, {0, 1, 3, 4}, {2}, {2},
  };
  vector<int> result = sol.dfs(adj);
  for (int val : result) {
    printf("%d ", val);
  }
  printf("\n");
  return 0;
}
