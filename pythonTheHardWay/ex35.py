from sys import exit

def GoldRoom():
    print("This room is full of gold. How much do you take?")

    choice = input("> ")
    if "0" in choice or "1" in choice:
        howMuch = int(choice)
    else:
        Dead("Man, learn to type a number.")

    if howMuch < 50:
        print("Nice, you're not greedy. You win!")
        exit(0)
    else:
        Dead("You greedy bastartd!")


def BearRoom():
    print("There is a bear here.")
    print("The bear has a bunch of honey.")
    print("The fat bear is in front of another door.")
    print("How are you going to move the bear?")
    bearMoved = False

    while True:
        choice = input("> ")

        if choice == "take honey":
            Dead("The bear looks at you then slaps your face off.")
        elif choice == "taunt bear" and not bearMoved:
            print("The bear has moved from the door.")
            print("You can go through it now.")
            bearMoved = True
        elif choice == "taunt bear" and bearMoved:
            Dead("The bear gets pissed off and chews your leg off.")
        elif choice == "open door" and bearMoved:
            GoldRoom()
        else:
            print("I got no idea what that means")

def CthulhuRoom():
    print("Here you see the great evil Cthulhu.")
    print("He, it, whatever stares at you and you go insane.")
    print("Do you flee for your life or eat your head?")

    choice = input("> ")

    if "flee" in choice:
        start()
    elif "head" in choice:
        Dead("Well that was tasty!")
    else:
        CthulhuRoom()

def Dead(why):
    print(why, "Good Job!")
    exit(0)

def Start():
    print("You are in a dark room.")
    print("There is a door to your right and left.")
    print("Which one do you take?")
    
    choice = input("> ")

    if choice == "left":
        BearRoom()
    elif choice == "right":
        CthulhuRoom()
    else:
        Dead("You stumble around the room until you starve.")

Start()
