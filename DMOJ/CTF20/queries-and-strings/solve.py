from base64 import b64decode

with open('query_strings.txt', 'r') as f:
    for line in f:
        s = line
        add = 3 - len(s) % 3;
        for i in range(add):
            s += '='
        print b64decode(s)
