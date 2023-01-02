def encode(s):
    return ''.join([hex(ord(c))[2:] for c in s][::-1])

def assemblify(s):
    for hexcode in ['0x' + s[max(0,i-8):i].zfill(8) for i in range(len(s), -1, -8)]:
        print(f".word {hexcode}")

def assembly(s):
    """
    Get an ASCII word and return the hex word 
    """
    assemblify(encode(s))

word = ''

print("Word len: {}\n".format(len(word)))
assembly(word)