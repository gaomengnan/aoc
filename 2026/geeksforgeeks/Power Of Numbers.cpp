#include <vector>
using namespace std;

#include <iostream>

class Solution {
public:
  int reverse(int n) {
    int rev = 0;
    while (n > 0) {
      int left = n % 10;
      n /= 10;
      rev = rev * 10 + left;
    }
    return rev;
  }

public:
  int reverseExponentiation(int n) {
    int rev = reverse(n);

    long long result = 1;
    while (rev > 0) {
      if (rev & 1) {
        result = result * n;
      }
      n = n * n;
      rev >>= 1;
    }

    return result;
  }
};

int main() {
    Solution solution;
    // Test case 1
    int num1 = 12;
    cout << "Reverse of " << num1 << " is: " << solution.reverse(num1) << endl;
    cout << "Reverse Exponentiation of " << num1 << " with its reverse as power is: " << solution.reverseExponentiation(num1) << endl;

    // Test case 2
    int num2 = 123;
    cout << "\nReverse of " << num2 << " is: " << solution.reverse(num2) << endl;
    cout << "Reverse Exponentiation of " << num2 << " with its reverse as power is: " << solution.reverseExponentiation(num2) << endl;

    return 0;
}

