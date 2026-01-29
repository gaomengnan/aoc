class Solution:
    def findTriplet(self, arr):
        #  2 9 10    21 / 2
        arr.sort()
        n = len(arr)

        for k in range(n - 1, -1, -1):
            # v = arr[k]
            i = 0
            j = k - 1

            while i < j:
                toSum = arr[j] + arr[i]

                if toSum == arr[k]:
                    return True

                if toSum < arr[k]:
                    i += 1
                else:
                    j -= 1

        return False


numbers = [
    6865,
    8921,
    22468,
    20392,
    27390,
    31530,
    8847,
    26964,
    20505,
    21692,
    7535,
    31540,
    18233,
    19549,
    30152,
    12717,
    28032,
    25526,
    23414,
    7868,
    26691,
    22744,
    18960,
    28208,
    6250,
    7192,
    30569,
    10775,
    7450,
    22557,
    2909,
]


print(Solution().findTriplet(numbers))
