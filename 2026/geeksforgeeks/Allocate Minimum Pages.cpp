/**
 Given an array arr[] of integers, where each element arr[i] represents the
number of pages in the i-th book. You also have an integer k representing the
number of students. The task is to allocate books to each student such that:
Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any
student. In other words, out of all possible allocations, find the arrangement
where the student who receives the most pages still has the smallest possible
maximum.

Note: If it is not possible to allocate books to all students, return -1

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
=> [12] and [34, 67, 90] Maximum Pages = 191
=> [12, 34] and [67, 90] Maximum Pages = 157
=> [12, 34, 67] and [90] Maximum Pages = 113.
The third combination has the minimum pages assigned to a student which is 113.


Input: arr[] = [15, 17, 20, 10, 30, 25], k = 3

  */
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  bool isPossible(vector<int> &arr, int n, int k, int mid) {

    int studentCount = 1;
    int pageSum = 0;

    for (int x : arr) {
      if (x > mid)
        return false;

      if (pageSum + x <= mid) {
        // studentCount++;
        pageSum += x;
      } else {
        studentCount++;
        pageSum = x;
        if (studentCount > k)
          return false;
      }
    }
    return true;
  };

public:
  int findPages(vector<int> &arr, int k) {
    int n = arr.size();
    if (k > n)
      return -1;
    int low = *max_element(arr.begin(), arr.end());
    int right = accumulate(arr.begin(), arr.end(), 0);

    int ans = -1;

    while (low <= right) {
      int mid = low + (right - low) / 2;
      if (isPossible(arr, n, k, mid)) {
        ans = mid;
        right = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    // code here
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {12, 34, 67, 90};
  int k = 2;
  int result = sol.findPages(arr, k);
  printf("%d\n", result); // Expected output: 113
  return 0;
}
