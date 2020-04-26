import sys
script, inputEncoding, error = sys.argv

def main(languageFile, encoding, errors):
    line = languageFile.readline()

    if line:
        PrintLine(line, encoding, errors)
        return main(languageFile, encoding, errors)

def PrintLine(line, encoding, errors):
    nextLang = line.strip()
    rawBytes = nextLang.encode(encoding, errors = errors)
    cookedString = rawBytes.decode(encoding, errors = errors)

    print(rawBytes, "<===>", cookedString)

languages = open("languages.txt", encoding = "utf-8")

main(languages, inputEncoding, error)
