# User function Template for python3
def find4Numbers(A, n, X):
    A.sort()
    for i in range(n - 3):
        for j in range(i + 1, n - 2):
            x = j + 1
            z = n - 1

            while x < z:
                toSum = A[i] + A[j] + A[x] + A[z]

                if toSum == X:
                    print(A[i], A[j], A[x], A[z])
                    return True
                elif toSum < X:
                    x += 1
                else:
                    z -= 1
    return False


print(find4Numbers([1, 5, 1, 0, 6, 0], 6, 7))
