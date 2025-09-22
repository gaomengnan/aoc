#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool isSubset(vector<int> &a, vector<int> &b) {

    unordered_map<int, int> st;
    int n = a.size();

    for (int i = 0; i < n; i++) {
      st[a[i]]++;
    }

    for (int i = 0; i < b.size(); i++) {
      if (st.find(b[i]) == st.end()) {
        return false;
      }
      st[b[i]]--;
      if (st[b[i]] == 0) {
        st.erase(b[i]);
      }
    }

    return true;
  }
};
int main() {
  Solution sol;
  vector<int> a = {1,2,2};
  vector<int> b = {1,1};
  if (sol.isSubset(a, b)) {
    cout << "b is a subset of a" << endl;
  } else {
    cout << "b is not a subset of a" << endl;
  }
  return 0;
}
