from sys import argv

script, inputFile = argv

def PrintAll(f):
    print(f.read())

def Rewind(f):
    f.seek(0)

def PrintALine(lineCount, f):
    print(lineCount, f.readline())

currentFile = open(inputFile)

print("First let's print the whole file:\n")

PrintAll(currentFile)

print("Now let's rewind, kind of like a tape.")
Rewind(currentFile)

print("Let's print three lines:")

currentLine = 1
PrintALine(currentLine, currentFile)

currentLine += 1
PrintALine(currentLine, currentFile)

currentLine += 1
PrintALine(currentLine, currentFile)
