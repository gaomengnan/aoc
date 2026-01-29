#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findUnion(vector<int> &a, vector<int> &b) {


  }
};

int main() {
  Solution sol;
  vector<int> a = {1, 2, 1, 3, 1};
  vector<int> b = {3, 1, 3, 4, 1};
  vector<int> result = sol.findUnion(a, b);
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
