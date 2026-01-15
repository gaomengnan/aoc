#include <vector>
using namespace std;

class Solution {
public:
  // Function to count the number of digits in n that evenly divide n
  int evenlyDivides(int n) {
    int calc = n;
    int ans = 0;
    while (calc > 0) {
      int res = calc % 10;
      if (res != 0 && n % res == 0) {
        ans++;
      }
      calc /= 10;
      // printf("%d \n", res);
    }

    return ans;
    // code here
  }
};

int main() {
  Solution sol;
  int n = 2446; // Example input
  int result = sol.evenlyDivides(n);
  printf("%d \n", result);
  return 0;
}
