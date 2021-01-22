from drunkenWalkClasses import Drunk
import random

class ColdDrunk(Drunk):
    def takeStep(self):
        stepChoices = [(0,1), (0,-2), (1,0), (-1,0)]
        return random.choice(stepChoices)

class EWDrunk(Drunk):
    def takeStep(self):
        stepChoices = [(1,0), (-1,0)]
        return random.choice(stepChoices)
