#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

vector<pair<string, int>> findCount(vector<vector<string>> arr) {
  vector<pair<string, int>> res;
  unordered_map<string, int> mp;
  unordered_map<string, string> ts;
  unordered_set<string> visited;

  for (auto &p : arr) {
    string a = p[0];
    string b = p[1];
    ts[a] = b;
  }
  for (auto &p : arr) {
    string a = p[0];
    mp[a] = 0;
  }

  for (auto &p : arr) {
    string a = p[0];
    string b = p[1];
    if (a == b) {
      continue;
    }
    string next = b;
    int starter = 0;
    if (!visited.count(a)) {
      starter = 1;
    }

    while (true) {
      mp[next] += starter;
      // 如果找到了next
      if (ts.find(next) != ts.end()) {
        if (!visited.count(next)) {
          starter++;
        }
        if (next == ts.find(next)->second) {
          break;
        }
        visited.insert(next);
        next = ts.find(next)->second;
        continue;
      }
      break;
    }
  }

  ///////////// LOG ///////////
  for (auto &p : mp) {
    // cout << p.first << " " << p.second << endl;
    res.push_back({p.first, p.second});
  }

  return res;
}

int main() {
  vector<vector<string>> arr = {{"A", "C"}, {"B", "C"}, {"C", "F"},
                                {"D", "E"}, {"E", "F"}, {"F", "F"}};

  vector<pair<string, int>> result = findCount(arr);

  // sort the result
  sort(result.begin(), result.end());
  for (auto i : result) {
    cout << i.first << ": " << i.second << endl;
  }
  return 0;
}
