print("Let's practice everything.")
print("You\'d need to know \'bout escapes with \\ that do")
print('\n new lines and \t tabs')

poem = """
\tThe lovely world
with logic so firmly planted
connot discern \n the needs of love
nor comprehend passion from intuition
and requires an explanation
\n\twhere there is none.
"""

print("------------")
print(poem)
print("------------")

five = 10 - 2 + 3 - 6
print(f"This should be five: {five}")

def SecretFormula(started):
    jellyBeans = started * 500
    jars = jellyBeans / 1000
    crates = jars / 100
    return jellyBeans, jars, crates

startPoint = 10000
beans, jars, crates = SecretFormula(startPoint)

print("With a starting point of: {}".format(startPoint))
print(f"We'd have {beans} beans, {jars} jars, and {crates} crates.")

startPoint = startPoint / 10

print("We can also do that this way:")
formula = SecretFormula(startPoint)
print("We'd have {} beans, {} jars, and {} crates.".format(*formula))
