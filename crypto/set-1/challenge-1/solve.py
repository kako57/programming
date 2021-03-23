from base64 import b64encode
# convert hex to base64
s = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"
ans = ""
n = len(s)
for i in range(0, n, 2):
    t = s[i:i+2]
    ans += chr(int(t, 16))
print(ans)
# TODO you got the message but now you should convert it to base64
n = len(ans)
ans = b64encode(ans.encode("utf-8"))
print(ans.decode())
