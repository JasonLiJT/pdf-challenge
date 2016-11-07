import base64
source = """
Keywords (R3VyIDNlcSBjbmZmcGJxciB2ZjogNjRndXJ6bnR2cGFoem9yZQ==)
Subject (guvf qbphzrag pbagnvaf fhcre frperg guvatf!)
"""

s = base64.b64decode(b"R3VyIDNlcSBjbmZmcGJxciB2ZjogNjRndXJ6bnR2cGFoem9yZQ==")
print(s)

# convert bitstring s to string
# delete b' and '
s = str(s)[2:-1]

# try shifting letters
for shift in range(26):
    lst = []
    for c in s:
        if c.isalpha():
            n = (ord(str(c)) + shift)
            if ((n > ord('z') and c.islower()) or
                    (n > ord('Z') and c.isupper())):
                n -= 26
            lst.append(chr(n))
        else:
            lst.append(c)
    print(shift, ''.join(lst))
