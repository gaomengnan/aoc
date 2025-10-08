#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define ll long long

class Solution {
public:
  string calculateFraction(int a, int b) {
    unordered_map<int, int> remainderPos;
    string result;

    long long x = llabs((long long)a);
    long long y = llabs((long long)b);

    ll intpart = x / y;

    ll remainder = x % y;
    // ll startLop = -1;
    // ll endLop = 0;
    result += to_string(intpart);
    if (remainder != 0) {
      result.push_back('.');
    }

    while (remainder != 0) {
      // ll p = (remainder * 10) / b;
      // ll nl = remainder * 10 - p * b;

      if (remainderPos.count(remainder)) {
        int pos = remainderPos[remainder];
        result.insert(pos, 1, '(');
        result.push_back(')');
        break;
      }

      remainderPos[remainder] = result.size();

      remainder *= 10;

      int digit = remainder / y;

      result.push_back('0' + digit);

      remainder %= y;
    }
    return result;
  }
};

int main() {
  Solution sol;
  int a = 1, b = 4;
  cout << sol.calculateFraction(a, b) << endl; // Output: "0.(3)"
  return 0;
}
