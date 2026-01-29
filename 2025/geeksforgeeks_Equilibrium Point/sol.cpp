#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  // Function to find equilibrium point in the array.
  int findEquilibrium(vector<int> &arr) {
    // code here
    int n = arr.size();
    vector<int> lefts(n);
    vector<int> rights(n);

    lefts[0] = arr[0];
    rights[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++) {
      lefts[i] = arr[i] + lefts[i - 1];
    }

    for (int i = n - 2; i > 0; i--) {
      rights[i] = arr[i] + rights[i + 1];
    };

    for (int x : lefts) {
        cout << x << " ";
    }
    cout << endl;


    for (int x : rights) {
        cout << x << " ";
    }
    cout << endl;


    for (int i = 1; i < n - 1; i++) {
      if (lefts[i - 1] == rights[i + 1]) {
        return i; // Return 1-based index
      }
    }

    return -1;
  };
};

int main() {
  Solution sol;
  vector<int> arr = {1,2,0,3};
  cout << sol.findEquilibrium(arr) << endl;
  return 0;
}
