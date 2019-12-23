from cs50 import get_string

while True:
    name = get_string("What is your name?\n")

    if len(name) > 0:
        break

print("hello, " + name)