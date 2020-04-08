def PrintTwo(*args):
    arg1, arg2 = args
    print(f"arg1: {arg1}, arg2: {arg2}")

def PrintTwoAgain(arg1, arg2):
    print(f"arg1: {arg1}, arg2: {arg2}")

def PrintOne(arg1):
    print(f"arg1: {arg1}")

def PrintNone():
    print("I got nothin'.")

PrintTwo("Zed", "Shaw")
PrintTwoAgain("Zed", "Shaw")
PrintOne("First!")
PrintNone()
