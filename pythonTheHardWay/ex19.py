def CheeseAndCrackers(cheeseCount, boxesOfCrackers):
    print(f"You have {cheeseCount} cheeses!")
    print(f"You have {boxesOfCrackers} crackers!")
    print("Man that's enough for a party!")
    print("Get a blanket\n")

print("We can just give the function numbers directly:")
CheeseAndCrackers(20, 30)

print("OR, we can use variables from out script:")
amountOfCheese = 10
amountOfCrackers = 50

CheeseAndCrackers(amountOfCheese, amountOfCrackers)

print("We can even do math inside too:")
CheeseAndCrackers(10 + 20, 5 + 6)

print("And we can combine the two, variabes and math:")
CheeseAndCrackers(amountOfCheese + 100, amountOfCrackers + 1000)
