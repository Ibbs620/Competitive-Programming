#NOTE: This solution is incomplete. Only 15/100 points were achieved.

import math

n, q = map(int, input().split())
a = [int(s) for s in input().split()]

for i in range(q):
    x, y = map(int, input().split())
    if x == 1:
        while y in a:
            a.remove(y)
            a.append(y//2)
            a.append(math.ceil(y/2))
    else:
        print(a.count(y))
