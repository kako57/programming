s = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal"

key = "ICE"

n = len(key)

es = ""
et = ""

for i, c in enumerate(s):
    es += "{:02x}".format(ord(c) ^ ord(key[i%n]))

print(es)

