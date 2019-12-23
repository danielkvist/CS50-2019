from cs50 import get_string
from sys import argv, exit
import re


def censor(text, banned):
    final = []
    for w in text:
        if (w.lower()).strip(",.!?") in banned:
            censored = re.sub('[a-zA-Z]', '*', w)
            final.append(censored)
        else:
            final.append(w)

    return ' '.join(final)


def main():
    if len(argv) != 2:
        print("Usage: python bleep.py dictionary")
        exit(1)

    dictionary = argv[1]
    with open(dictionary, 'r', encoding="UTF-8") as f:
        lines = [line.rstrip() for line in f]

    censored = input("What message would you like to censor? ")
    censored = censored.split()
    censored = censor(censored, lines)
    print(censored)


if __name__ == "__main__":
    main()
