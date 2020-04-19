import random

class Item(object):
    def __init__(self, n, v, w):
        self.name = n
        self.value = v
        self.weight = w

    def getName(self):
        return self.name

    def getValue(self):
        return self.value

    def getWeight(self):
        return self.weight

    def __str__(self):
        result = '<' + self.name + ', ' + str(self.value) + ', ' + str(self.weight) + '>'
        return result


def maxVal(toConsider, avail):
    """Assumes toConsider a list of items, avail a weight
        Returns a tuple of the total value of a solution to the
        0/1 knapsack problem and the items of that solution"""

    if toConsider == [] or avail == 0:
        result = (0, ())
    elif toConsider[0].getWeight() > avail:
        result = maxVal(toConsider[1:], avail)
    else:
        nextItem = toConsider[0]

        #left branch
        withVal, withToTake = maxVal(toConsider[1:], avail - nextItem.getWeight())
        withVal += nextItem.getValue()

        #right branch
        withoutVal, withoutToTake = maxVal(toConsider[1:], avail)

        #choose better branch

        if withVal > withoutVal:
            result = (withVal, withToTake + (nextItem,))
        else:
            result = (withoutVal, withoutToTake)
    return result

def smallTest():
    names = ['a', 'b', 'c', 'd']
    vals = [6, 7, 8, 9]
    weights = [3, 3, 2, 5]
    items = []
    for i in range(len(vals)):
        items.append(Item(names[i], vals[i], weights[i]))
    val, taken = maxVal(items, 5)
    for item in taken:
        print(item)
    print('Total value of items taken =', val)

def buildManyItems(numItems, maxVal, maxWeight):
    items = []
    for i in range(numItems):
        items.append(Item(str(i), random.randint(1, maxVal), random.randint(1, maxWeight)))
    return items

def bigTest(numItems):
    items = buildManyItems(numItems, 10, 10)
    val, taken = maxVal(items, 40)
    print("Items Taken")
    for item in taken:
        print(item)
    print('Total value of items taken =', val)

smallTest()
bigTest(25)
