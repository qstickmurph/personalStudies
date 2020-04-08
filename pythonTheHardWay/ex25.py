def BreakWords(stuff):
    words = stuff.split(" ")
    return words

def SortWords(words):
    return sorted(words)

def PrintFirstWord(words):
    word = words.pop(0)
    print(word)

def PrintLastWord(words):
    word = words.pop(-1)
    print(word)

def SortSentence(sentence):
    words = BreakWords(sentence)
    return SortWords(words)

def PrintFirstAndLast(sentence):
    words = BreakWorkds(sentence)
    PrintFirstWord(words)
    PrintLastWord(Words)

def PrintFirstAndLastSorted(sentence):
    words = SortSentence(sentence)
    PrintFirstWord(words)
    PrintLastWord(words)
