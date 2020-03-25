def LinearSearch(L, e):
    """Assumes L is a list.
        Returns True if e is in L and False otherwise"""
    for i in range(len(L)):
        if L[i] == e:
            return True
    return False
