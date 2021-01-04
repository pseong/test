# n = number of types of tiles
# m = size of the square to make

# 2n lines of the test case = descriptions of tiles types
#

0 1 2 3
1 0 5 9
2 5 0 7
3 9 7 0


t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    result = False
    for _ in range(n):
        t1, t2 = map(int, input().split())
        t3, t4 = map(int, input().split())
        if t2 == t3:
            result = True
        if m % 2 == 1:
            result = False
    if result == True:
        print("YES")
    else:
        print("NO")