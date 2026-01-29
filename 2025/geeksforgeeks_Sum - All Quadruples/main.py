from collections import defaultdict


class Solution:
    def fourSum(self, arr, target):
        arr.sort()

        n = len(arr)

        pair_sums = defaultdict(list)

        results = []

        for i in range(n):
            for j in range(i + 1, n):
                # print(i, j)

                pre_sum = arr[i] + arr[j]

                left_sum = target - pre_sum

                for z in pair_sums[left_sum]:
                    # print("sum", z)
                    # print("i=",arr[i],"j=", arr[j])
                    results.append(z + [arr[i], arr[j]])

            # k< i
            for k in range(i):
                toSum = arr[k] + arr[i]

                pair_sums[toSum].append([arr[k], arr[i]])

        unique_sorted_data = [list(item) for item in set(tuple(sub) for sub in results)]

        return unique_sorted_data
