import sys

write = sys.stdout.write
read = sys.stdin.readline
flush = sys.stdout.flush
xr = range

n, p = map(int, read().split())
for i in xr(n):
    read()
print(p)
