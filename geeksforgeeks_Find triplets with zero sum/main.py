  class Solution:
    def findTriplets(self, arr):
        #code here

        # -3 -1 0 1 2
        #

        arr.sort()


        n = len(arr)

        for cur in range(n):
            i = cur + 1
            j = n-1
            while i < j :
                toSum = arr[cur] + arr[i] + arr[j]
                if toSum ==0:
                    return True

                elif toSum > 0:
                    j -=1
                else:
                    i +=1



        return False
