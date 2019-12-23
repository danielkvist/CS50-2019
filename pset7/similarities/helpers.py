from nltk.tokenize import sent_tokenize

def lines(a, b):
    """Return lines in both a and b"""

    lines_a = set(a.split("\n"))
    lines_b = set(b.split("\n"))
    return lines_a & lines_b


def sentences(a, b):
    """Return sentences in both a and b"""

    sentences_a = set(sent_tokenize(a))
    sentences_b = set(sent_tokenize(b))
    return sentences_a & sentences_b


def tokenize(str, n):
    toks = []
    for i in range(len(str) - n + 1):
        toks.append(str[i:i + n])
    return toks


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    substrings_a = set(tokenize(a, n))
    substrings_b = set(tokenize(b, n))
    return substrings_a & substrings_b
