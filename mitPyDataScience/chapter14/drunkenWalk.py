from drunkenWalkClasses import Location, Field, Drunk, UsualDrunk
from newDrunks import ColdDrunk, EWDrunk

def walk(f, d, numSteps):
    """Assumes f is a Field, d is a Drunk in f, and numSteps is an int >= 0
       Moves d numSteps times; returns the distance between the final location
       and the location at the start of the walk. """

    start = f.getLoc(d)
    for s in range(numSteps):
        f.moveDrunk(d)
    return start.distFrom(f.getLoc(d))

def simWalks(numSteps, numTrials, dClass):
    """Assumes numSteps an int >= 0, numTrials an int >= 0.
       dClass a subclass of Drunk."""

    homer = dClass()
    origin = Location(0,0)
    distances = []
    for t in range(numTrials):
        f = Field()
        f.addDrunk(homer, origin)
        distances.append(round(walk(f, homer, numSteps), 1))
    return distances

def drunkTest(walkLengths, numTrials, dClass):
    """Assumes walkLengths is a sequence of ints >= 0,
       numTrials is an int >= 0, dClass a subclass of Drunk.
       For each number of steps in walkLengths, runs simWalks with
       numTrials walks and prints results"""

    for numSteps in walkLengths:
        distances = simWalks(numSteps, numTrials, dClass)
        print(dClass.__name__, 'random walk of', numSteps, 'steps.')
        print(' Mean =', round(sum(distances)/len(distances), 4))
        print(' Max =', max(distances), 'Min =', min(distances))

def simAll(drunkKinds, walkLengths, numTrials):
    for dClass in drunkKinds:
        drunkTest(walkLengths, numTrials, dClass)

if __name__ == '__main__':
    drunkKinds = [UsualDrunk, ColdDrunk, EWDrunk]
    walkLengths = (10, 100, 1000, 10000)
    numTrials = 100
    simAll(drunkKinds, walkLengths, numTrials)
