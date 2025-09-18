# User function Template for python3
class solution:
    def commonSlot(a, b, d):
        i = 0
        j = 0

        while i < len(a) and j < len(b):
            va = a[i]
            vb = b[j]

            m1 = max(va[0], vb[0])
            m2 = min(va[1], vb[1])

            if m2 - m1 >= d:
                return [m1, m1 + d]
            else:
                if va[1] > vb[1]:
                    j += 1
                else:
                    i += 1

        return []


a = [[10, 50], [60, 120], [140, 210]]
b = [[0, 15], [60, 70]]

print(solution.commonSlot(a, b, 8))

a1 = [[10, 50], [60, 120], [140, 210]]
b1 = [[0, 15], [60, 70]]
print(solution.commonSlot(a1, b1, 12))
