def binarySearch(L, e):
    """Assumes L is a list, the elements of which are in ascending order.
        returns True if e is in L and False otherwise"""
    for i in range(len(L)):
        if L[i] == e:
            return True
        if L[i] > e:
            return False
    return False
