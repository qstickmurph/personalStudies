from sys import argv

script, filename = argv

print(f"We're going to erase {filename}")
print("If you don't want that, hit CTRl-C (^C)")
print("If you do want that, hit return")

input("?")

print("Opening the file . . .")
target = open(filename, "w")

print("Truncating the file . . .", end = ' ')
target.truncate()
print("Goodbye!")

print("Now I'm going to ask you for three lines")

line1 = input("line1 = ")
line2 = input("line2 = ")
line3 = input("line3 = ")

print("I'm going to write thses to the file.")

target.write(line1 + "\n")
target.write(line2 + "\n")
target.write(line3 + "\n")

print("And finally, we close it.")
target.close()
