from string import printable

def score(s):
    score = 0
    for c in s:
        if 67 <= ord(c) <= 90 or 97 <= ord(c) <= 122 or c == ' ':
            score += 1
    return score

def scxor(s):
    mx = 0
    best = ""
    key = ' '
    for k in printable:
        t = ""
        for c in b:
            t += chr(c ^ ord(k))
            if all([i in printable for i in t]):
                sc = score(t)
                if sc > mx:
                    mx = sc
                    best = t
                    key = k
    return mx, best, key

with open("4.txt", "r") as f:
    candidates = []
    for i, s in enumerate(f, 1):
        b = bytearray.fromhex(s)
        candidates.append(scxor(b))
    candidates.sort()
    for c in candidates:
        print(c)
