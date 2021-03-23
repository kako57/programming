import sys
import math

def happ(x):
    visited = set()
    while (x != 1):
        if x in visited:
            return ":("
        else:
            visited.add(x)
        nx = 0
        while x:
            nx += (x % 10) ** 2
            x /= 10
        print('weee')
        x = nx
    return ":)"

n = int(input())
for i in range(n):
    x = int(input())
    print("{} {}".format(x, happ(x)))
