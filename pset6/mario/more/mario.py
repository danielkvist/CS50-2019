from cs50 import get_int

while True:
    h = get_int("Height: ")
    w = h

    if h >= 1 and h <= 8:
        break

for i in range(1, h + 1):
    hashes = i
    spaces = w - hashes

    print(" " * spaces, end="")
    print("#" * hashes, end="")
    print("  ", end="")
    print("#" * hashes)