class Solution:
    def maxFruits(self, arr, totalTime):
        slow = 0
        fast = 0
        win_num = 0
        win_cost_time = totalTime
        ans = 0

        while fast < len(arr):
            # start collect
            win_num += arr[fast]
            ans = max(ans, win_num)

            win_cost_time -= 0.5  # collect cost

            # == 0 current not collect
            # -0.5 more one step
            # while win_cost_time <= 0:
            #     # left
            #     pass
            while win_cost_time <= 0.5:
                # back fruit
                win_cost_time += 0.5
                win_num -= arr[slow]
                slow += 1
                win_cost_time += 0.5

            # next
            win_cost_time -= 0.5
            fast += 1

        return ans


print(Solution().maxFruits([2, 1, 3, 50, 5, 5, 100, 1], 3))
print(Solution().maxFruits([2, 1, 3, 5, 0, 1, 4], 3))
print(Solution().maxFruits([1, 6, 2, 5, 3, 4], 2))
# 2 1 3  1 + 1.5
