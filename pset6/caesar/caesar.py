import sys
from cs50 import get_string


if len(sys.argv) != 2:
    print("Usage: ./caesar k")
    sys.exit(1)

k = int(sys.argv[1])
plaintext = get_string("plaintext: ")

print("ciphertext: ", end="")

for ch in plaintext:
    if not ch.isalpha():
        print(ch, end="")
        continue

    offset = 65 if ch.isupper() else 97
    pi = ord(ch) - offset
    ci = (pi + k) % 26
    print(chr(ci + offset), end="")

print()