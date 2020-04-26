from sys import argv

script, filename = argv

print("How old are you?", end=' ')
age = input()
print("How tall are you?", end=' ')
height = input()
print("How much do you weigh?", end=' ')
weight = input()

print(f"So, you're {age} old, {height} tall, and {weight} heavy.")


txt = open(filename)

print("Here's your file {filename}:")
print(txt.read())

print("Type the filename again:")
fileAgain = input("> ")

txtAgain = open(fileAgain)

print(txtAgain.read())


print('Let\'s practice everything.')
print('You\'d need to know \'bout escapes with \\ that do \n newlines and \t tabs.')

poem = """
\tThe lovely world
with logic so firmly planted
cannot discern \n the needs of love
nor comprehend passion from intuition
and requires an explanation
\n\t\twhere there is none.
"""

print("--------------")
print(poem)
print("--------------")


five = 10 - 2 + 3 - 6
print(f"This should be five: {five}")

def SecretFormula(started):
    jellyBeans = started * 500
    jars = jellyBeans / 1000
    crates = jars / 100
    return jellyBeans, jars, crates


startPoint = 10000
beans, jars, crates = SecretFormula(startPoint)

# remember that this is another way to format a string
print("With a starting point of: {}".format(startPoint))
# it's just like with an f"" string
print(f"We'd have {beans} beans, {jars} jars, and {crates} crates.")

startPoint = startPoint / 10

print("We can also do that this way:")
formula = SecretFormula(startPoint)
# this is an easy way to apply a list to a format string
print("We'd have {} beans, {} jars, and {} crates.".format(*formula))


people = 20
cats = 30
dogs = 15


if people < cats:
    print("Too many cats! The world is doomed!")

if people < cats:
    print("Not many cats! The world is saved!")

if people < dogs:
    print("The world is drooled on!")

if people > dogs:
    print("The world is dry!")


dogs += 5

if people >= dogs:
    print("People are greater than or equal to dogs.")

if people <= dogs:
    print("People are less than or equal to dogs.")


if people == dogs:
    print("People are dogs.")

