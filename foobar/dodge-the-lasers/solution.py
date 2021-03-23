from decimal import Decimal, getcontext

getcontext().prec = 200

def solution(s):
    nf = Decimal(2).sqrt() - 1
    def series(n):
        return n * (n + 1) // 2
    def next(n):
        return long(n * (nf))
    x = long(s)
    y = next(x)
    ans = 0
    sign = 1
    while x:
        ans += sign * (x * y + series(x) - series(y))
        x = y
        y = next(x)
        sign *= -1
    return str(ans)

print solution('5')
print solution('77')
print type(solution('5'))
print type(solution('77'))

assert (solution('5') == '19')
assert (solution('77') == '4208')

print(solution(str(10**101)))
