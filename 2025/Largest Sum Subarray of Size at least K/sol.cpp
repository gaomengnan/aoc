#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  long long maxSumWithK(long long a[], long long n, long long k) {
    vector<long long> max_end_here(n);
    max_end_here[0] = a[0];

    // Step 1: Kadane’s prefix
    for (int i = 1; i < n; i++)
      max_end_here[i] = max(a[i], a[i] + max_end_here[i - 1]);

    // Step 2: sum of first k elements
    long long sum = 0;
    for (int i = 0; i < k; i++)
      sum += a[i];

    long long ans = sum;

    // Step 3: Sliding window + combine
    for (int i = k; i < n; i++) {
      sum += a[i] - a[i - k];
      ans = max(ans, sum);
      ans = max(ans, sum + max_end_here[i - k]);
    }

    return ans;
  }
};
  int main() {
    long long int a[] = {-4, -2, 1, -3};
    long long int n = sizeof(a) / sizeof(a[0]);
    long long int k = 2;
    Solution sol;
    cout << sol.maxSumWithK(a, n, k) << endl; // Output: 12
    return 0;
  }
