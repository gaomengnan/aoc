#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// User function Template for C++
class Solution {
public:
  bool search(string &txt, string &pat) {

    unordered_map<char, int> mset;

    for (int i = 0; i < pat.size(); i++) {
      mset[pat[i]]++;
    }

    int k = pat.size();

    unordered_map<char, int> win;

    int left = 0;

    for (int right = 0; right < txt.size(); right++) {
      win[txt[right]]++;

      if (right - left + 1 > k) {
        while (right - left + 1 > k) {
          if (--win[txt[left]] == 0)
            win.erase(txt[left]);
          left++;
        }
      }

      if (right - left + 1 == k && win == mset)
        return true;
    }

    return false;
  }
};
int main() {
  Solution sol;
  string txt = "geeks";
  string pat = "kee";
  cout << sol.search(txt, pat) << endl; // Output: 39
  return 0;
}
