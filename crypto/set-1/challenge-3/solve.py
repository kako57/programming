from string import printable

s = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736"

b = bytearray.fromhex(s)

print(b)

for k in printable:
    t = ""
    for c in b:
        t += chr(c ^ ord(k))
    if all([i in printable for i in t]):
        print(f'{t} key: {k}')
