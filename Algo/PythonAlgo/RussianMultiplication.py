#Russian Peasants Algorithm
#Ancient Egyptians

def russian(a, b):
    x = a; y = b
    z = 0
    while x > 0:
        if x%2 == 1:
            z = z + y
        # >> halves the number
        y = y << 1
        x = x >> 1
    return z

print(russian(6, 3))
input()
