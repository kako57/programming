c = 10247955272908064997771727568918647737311526262165262458875076213296879253353684001266750329
e = 65537
n = 14393188157100504374851319373504728765762087532393762203410288659620743314524046223483350199

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a
    #return a if b == 0 else gcd(b, a%b)

def lcm(a, b):
    return a * b // gcd(a, b)

def pq(n):
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return i, n // i

def totient(p, q):
    return lcm(p - 1, q - 1)

def power(a, b, p):
    ans = 1
    while b:
        if b % 2:
            ans = (ans * a) % p
        a = (a * a) % p
        b //= 2
    return ans

def modular_inverse(a, m):
    assert(gcd(a,m) == 1)
    m0, y, x = m, 0, 1
    if m == 1:
        return 0
    while a > 1:
        q = a // m
        a, m = m, a % m
        x, y = y, x - q * y
    if x < 0:
        x += m0
    return x

p, q = pq(n)
l = totient(p, q)
d = modular_inverse(e, l)
m = power(c,d,n)

ans = hex(m)[2:]
ans = bytes.fromhex(ans).decode("utf-8")
print(ans)
