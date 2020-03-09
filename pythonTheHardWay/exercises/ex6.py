typesOfPeople = 10 
x = f"There are {typesOfPeople} types of people." # here

binary = "binary"
doNot = "don't"
y = f"Those who know {binary} and those who {doNot}" # here

print(x)
print(y)

print(f"I said: {x}") # here
print(f"I also said: '{y}'") # here

hilarious = False
jokeEvaluation = "Isn't that joke so funny?! {}" # here

print(jokeEvaluation.format(hilarious)) # here

w = "This is the left side of ..."
e = "a string with a right side."

print(w + e)
