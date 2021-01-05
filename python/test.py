import math

t = int(input())

for _ in range(t):
    n = int(input())
    a = int(math.sqrt(n))
    b = math.ceil(n / a)
    print(a + b - 2)