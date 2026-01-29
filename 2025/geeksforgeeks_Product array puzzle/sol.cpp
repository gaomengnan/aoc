#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &arr) {
    int n = arr.size();
    vector<int> pres(n);
    vector<int> subs(n);
    pres[0] = arr[0];

    subs[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++) {
      pres[i] = arr[i] * pres[i - 1];
    }

    for (int i = n - 2; i >= 0; i--) {
      subs[i] = arr[i] * subs[i + 1];
    }

    // for (int num : pres) {
    //   cout << num << " ";
    // }
    // cout << endl;

    // for (int num : subs) {
    //   cout << num << " ";
    // }
    // cout << endl;

    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
      if (i == 0) {
        ans[i] = subs[i + 1];
      } else if (i == n - 1) {
        ans[i] = pres[i - 1];
      } else {
        ans[i] = pres[i - 1] * subs[i + 1];
      }
    };
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {12, 0};
  vector<int> result = sol.productExceptSelf(arr);
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
