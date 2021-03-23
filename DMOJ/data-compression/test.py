a = ""
with open('output.txt', 'r') as f:
  a = f.read()

s = ''

n = len(a)
p = ''
c = 0
for i in range(0, n):
  if s[i] == p:
    c += 1
  else:
    s += p
    c = 1
