s = "1c0111001f010100061a024b53535009181c"
t = "686974207468652062756c6c277320657965"

# int converts hexstring to decimal
# hex returns str

print(hex(int(s, 16) ^ int(t, 16))[2:])

