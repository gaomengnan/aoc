#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int left = 0;

        int right = n - 1;

        vector<int> ans;
        int preDif = INT_MAX;

        while (left < right) {
            cout << "preDif" << preDif << endl;
            int preSum = arr[left] + arr[right];
            int preD = abs(preSum - target);
            if (preD < preDif) {
                preDif = preD;
                ans = {arr[left], arr[right]};
            }

            if (preSum == target) {
                // left ++;
                return {arr[left], arr[right]};
            }else if (preSum < target) {
                left ++;
            }else {
                right --;
            }

        }
        return ans;
    }
};

int main() {
    Solution sol;
    // 1 2 4 5 7
    vector<int> arr = {10};
    int target = 10;

    vector<int> res = sol.sumClosest(arr, target);
    if(res.size() > 0)
    	cout << res[0] << " " << res[1];

    return 0;
}
