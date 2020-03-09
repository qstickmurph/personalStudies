from sys import argv

script, filename = argv

txt = open(filename)

print(f"Here's your file {filename}")
print(txt.read())

print("Type the filename again:")
fileAgain = input("> ")

txt_again = open(fileAgain)

print(txt_again.read())

close(txt)
close(txtAgain)
