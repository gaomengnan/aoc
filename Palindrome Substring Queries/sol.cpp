#include <vector>
#include <print>
using namespace std;

class Solution {
public:
  bool ispal(string &s, int start, int end) {
    while (start < end) {
      if (s[start] != s[end]) {
        return false;
      }
      start++;
      end--;
    }
    return true;
  }
  vector<int> palQueries(string &s, vector<vector<int>> &queries) {
    vector<int> res;
    vector<char> chars(s.begin(), s.end());

    for (int i = 0; i < queries.size(); i++) {
      int l = queries[i][0];
      int r = queries[i][1];
      if (ispal(s, l, r)) {
        res.push_back(1);
      } else {
        res.push_back(0);
      }
    }
    return res;
  }
};

int main() {
  Solution sol;
  string s = "ababa";
  vector<vector<int>> queries = {{0, 2}, {1, 4}, {0, 4}};
  vector<int> results = sol.palQueries(s, queries);
  println("results is {}", results);
  return 0;
}
