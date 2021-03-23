from base64 import b64decode
from string import printable

def score(s):
    score = 0
    for c in s:
        if 67 <= ord(c) <= 90 or 97 <= ord(c) <= 122 or c == ' ':
            score += 1
    return score

def scxor(s): # single char xor
    res = []
    for k in printable:
        t = ""
        for c in s:
            t += chr(ord(c) ^ ord(k))
        if all(i in printable for i in t):
            sc = score(t)
            res.append((sc, t, k))
    return res

def hamming_distance(s, t):
    ans = 0
    for c, d in zip(s, t):
        ans += bin(ord(c) ^ ord(d)).count("1")
    return ans

ciphertext = ""
with open("6.txt", "r") as f:
    for l in f:
        ciphertext += b64decode(l).decode()

# finding the keysize

keysizes = []
for ks in range(2, 41):
    keysizes.append((hamming_distance(ciphertext[:ks], ciphertext[ks:ks+ks]) // ks, ks))
keysizes.sort()

#for i in keysizes:
#    print(i)

keysizes = [l for _,l in keysizes]

keys = []

for keysize in keysizes:
    blocks = [""] * keysize

    for i, c in enumerate(ciphertext):
        blocks[i % keysize] += c

    k = ""
    rsc = 0

    for b in blocks:
        wee = scxor(b)
        wee.sort()
        # for w in wee:
        #     print(w)
        if len(wee):
            #print(wee[-1])
            k += wee[-1][-1]
            rsc += wee[-1][0]

    if len(k):
        keys.append((rsc, k))

keys.sort()
#for k in keys:
#    print(k)

key = keys[-1][-1]
n = len(key)

decrypted = ""
for i, c in enumerate(ciphertext):
    decrypted += chr(ord(key[i % n]) ^ ord(c))

print(decrypted)
print(f'key: "{key}"')

