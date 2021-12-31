n = int(input())
vert = [int(s) for s in input().split()]
hor = [int(s) for s in input().split()]
area = 0
for i in range(n):
    area += (vert[i] + vert[i+1]) * hor[i] / 2

print(area)