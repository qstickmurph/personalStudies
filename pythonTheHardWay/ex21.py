def Add(a, b):
    print(f"ADDING {a} and {b}")
    return a + b

def Subtract(a, b):
    print(f"SUBTRACTING {a} and {b}")
    return a - b

def Multiply(a , b):
    print(f"MULTIPLYING {a} and {b}")
    return a * b

def Divide(a, b):
    print(f"DIVIDING {a} and {b}")
    return a / b

print("Let's do some math with just functions")

age = Add(30, 5)
height = Subtract(78, 4)
weight = Multiply(90, 2)
iq = Divide(100, 2)

print(f"Age: {age}, Height: {height}, Weight: {weight}, IQ: {iq}")

#Here is a puzzle for the extra credit
print("Here is a puzzle")

what = Add(age, Subtract(height, Multiply(weight, Divide(iq, 2))))
print(what == -4391)
