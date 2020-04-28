###########################
# 6.0002 Problem Set 1a: Space Cows 
# Name: Quinn Murphey
# Collaborators: None
# Time: April 25 2020

from ps1_partition import get_partitions
import time

#================================
# Part A: Transporting Space Cows
#================================

# Problem 1
def load_cows(filename):
    """
    Read the contents of the given file.  Assumes the file contents contain
    data in the form of comma-separated cow name, weight pairs, and return a
    dictionary containing cow names as keys and corresponding weights as values.

    Parameters:
    filename - the name of the data file as a string

    Returns:
    a dictionary of cow name (string), weight (int) pairs
    """
    weights = {}
    f = open(filename, "r")
    lines = f.readlines()
    lines = [line.split(',') for line in lines]
    for line in lines:
        weights[line[0]] = (int)(line[1])
    return weights

# Problem 2
def greedy_cow_transport(cows,limit=10):
    """
    Uses a greedy heuristic to determine an allocation of cows that attempts to
    minimize the number of spaceship trips needed to transport all the cows. The
    returned allocation of cows may or may not be optimal.
    The greedy heuristic should follow the following method:

    1. As long as the current trip can fit another cow, add the largest cow that will fit
        to the trip
    2. Once the trip is full, begin a new trip to transport the remaining cows

    Does not mutate the given dictionary of cows.

    Parameters:
    cows - a dictionary of name (string), weight (int) pairs
    limit - weight limit of the spaceship (an int)
    
    Returns:
    A list of lists, with each inner list containing the names of cows
    transported on a particular trip and the overall list containing all the
    trips
    """
    result = []
    tempCows = cows
    
    while len(tempCows) > 0: # loop until no cows remain
        trip = []
        currentWeight = 0
        while currentWeight < limit and len(tempCows) > 0: # loop until spaceship is full
            currentCow = (None,0) # base cow
            for cow in tempCows.items(): # find max cow
                if cow[1] > currentCow[1] and currentWeight + cow[1] <= limit:
                    currentCow = cow
            if currentCow == (None, 0):
                break
            trip.append(currentCow[0])
            tempCows.pop(currentCow[0])
            currentWeight += currentCow[1]
        result.append(trip)

    return result

# Problem 3
def brute_force_cow_transport(cows,limit=10):
    """
    Finds the allocation of cows that minimizes the number of spaceship trips
    via brute force.  The brute force algorithm should follow the following method:

    1. Enumerate all possible ways that the cows can be divided into separate trips 
        Use the given get_partitions function in ps1_partition.py to help you!
    2. Select the allocation that minimizes the number of trips without making any trip
        that does not obey the weight limitation
            
    Does not mutate the given dictionary of cows.

    Parameters:
    cows - a dictionary of name (string), weight (int) pairs
    limit - weight limit of the spaceship (an int)
    
    Returns:
    A list of lists, with each inner list containing the names of cows
    transported on a particular trip and the overall list containing all the
    trips
    """
    
    cowList = []
    for name, weight in cows.items():
        tempList = [name, weight]
        cowList.append(tempList)

    indexList = []
    for i in range(len(cowList)):
        indexList.append(i)
    
    minTrips = len(cowList)
    bestRun = None
    for partition in get_partitions(indexList): # loop over every partition
        tripCount=0
        valid = True
        for trip in partition: # loop over each trip in partition
            weightSum = 0
            tripCount += 1
            for index in trip: # sum weight of each trip
                weightSum += cowList[index][1]
            if weightSum > limit:
                valid = False
                # print("Denied {} because trip {} had weight {}".format(partition, trip, weightSum))
                break
        if valid and tripCount < minTrips: 
            bestRun = partition
            minTrips = len(bestRun)
        elif valid:
            print(f"Denied {partition} because {tripCount} >= {minTrips}")
    
    print(bestRun)
    result = []
    for trip in bestRun:
        temp = []
        for index in trip:
            temp.append(cowList[index])
        result.append(temp)
    
    return result



        
# Problem 4
def compare_cow_transport_algorithms():
    """
    Using the data from ps1_cow_data.txt and the specified weight limit, run your
    greedy_cow_transport and brute_force_cow_transport functions here. Use the
    default weight limits of 10 for both greedy_cow_transport and
    brute_force_cow_transport.
    
    Print out the number of trips returned by each method, and how long each
    method takes to run in seconds.

    Returns:
    Does not return anything.
    """
    # TODO: Your code here
    pass

#print(greedy_cow_transport(load_cows('ps1_cow_data.txt'), 10))
print(brute_force_cow_transport(load_cows('ps1_cow_data.txt'), 10))
