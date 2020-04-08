i = 0
numbers = []

while i < 6:
    print(f"At the top, i is {i}")
    numbers.append(i)
    i += 1
    
    print("Numbers now: ", numbers)
    print(f"At the bottom, i is {i}")

print("The numbers: ")

for num in numbers:
    print(num)

#Study drill 1
def CreateNumberList(mi, ma, inc = 1):
    numbers = []
    i = mi
    while i < ma:
        print(f"At the top, i is {i}")
        numbers.append(i)
        i += inc
        
        print("Numbers now: ", numbers)
        print(f"At the bottom, i is {i}")
