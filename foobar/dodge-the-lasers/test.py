def aseries(n):
  return n * (n + 1) // 2

def solution(s):
  x = int(s)
  if x == 0:
    return '0'
  y = int(x * ((2 ** 0.5) - 1))
  return str(x * y + aseries(x) - aseries(y) - int(solution(y)))

print(solution('77'))
