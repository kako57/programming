#!/usr/bin/pypy
from base64 import b64decode

s = "Gk0fFhYRBBIZS0NPUkYGGAkCAVVNQU0PDBkeBAANGQZSUltBTQkQARcEDA8IRFlSRgQMCgwHBhJGSlZDUhsPAhgJBxwQDQRNQENSEwIJAwkVEB8EDx5LQ09SRhQEAAwWGQQFTUBDUgAAAwgFFwZVQVtKSxAUFARGRkxEEx0ORkpWQ1IFCA9LSx4="

decoded = b64decode(s)

key = "ajlcura"

ans = ""

for i, j in enumerate(decoded):
    ans += chr(ord(j) ^ ord(key[i % len(key)]))

print ans
