from sys import argv
from os.path import exists

script, fromFile, toFile = argv

print(f"Copying from {fromFile} to {toFile}")

inFile = open(fromFile)
inData = inFile.read()

print(f"The input file is {len(inData)} bytes long")

print(f"Does the output file exist? {exists(toFile)}")
print("Ready? Hit RETURN to continue, CRTL-C to abort")
input()

outFile = open(toFile, "w")
outFile.write(inData)

print("Alright, all done")

outFile.close()
inFile.close()
