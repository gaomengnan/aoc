#include <vector>
#include <print>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
  public:
    vector<int> getThreeLargest(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), greater<int>());
        vector<int> res;
        // res[0] = arr[0];
        for(int i = 0; i < n;i++) {
            if (res.size() == 3) {
                break;
            }

            if (res.empty() || res.back() != arr[i] ) {
                res.push_back(arr[i]);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {10, 4, 3, 50, 23, 90, 90};
    vector<int> result = sol.getThreeLargest(arr);
    print("Three largest elements are: {}", result);
    return 0;
}
