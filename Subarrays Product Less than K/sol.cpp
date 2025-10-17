#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long countSubArrayProductLessThanK(const vector<int>& nums, long long k) {
        if (k <= 1) return 0;

        long long prod = 1;
        int left = 0;
        long long ans = 0;

        for (int right = 0; right < nums.size(); ++right) {
            prod *= nums[right];

            while (prod >= k && left <= right) {
                prod /= nums[left];
                ++left;
            }

            // 每个以 right 为结尾的子数组中，有 (right - left + 1) 个合法的
            ans += right - left + 1;
        }

        return ans;
    }
};

int main() {
    vector<int> arr = {2, 2, 3, 4};
    int k = 40;
    Solution sol;
    cout << sol.countSubArrayProductLessThanK(arr, k) << endl;
    return 0;
}
