#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> fizzBuzz(int n) {

    vector<string> ans(n);

    for (int i = 1; i <= n; i++) {

      if (i % 5 == 0 and i % 3 == 0) {
        ans.push_back("FizzBuzz");
      }else if (i % 3 == 0) {
        ans.push_back("Fizz");
      }else if (i % 5 ==0) {
        ans.push_back("Buzz");
      }else{
        ans.push_back(to_string(i));
      }

    }

    return ans;
  }
};
int main() {
  Solution sol;
  int n = 15; // Example input
  vector<string> result = sol.fizzBuzz(n);

  // Print the result
  for (const string &s : result) {
    cout << s << " ";
  }

  return 0;
}
