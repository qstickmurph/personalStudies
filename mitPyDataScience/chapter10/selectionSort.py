def selSort(L):
    """Assumes L is a llist of elements that can be compared using >.
        Sorts L in ascending order."""
    suffixStart = 0
    while suffixStart != len(L):
        #look at each element in suffix
        for i in range(suffixStart, len(L)):
            if L[i] < L[suffixStart]:
                #swap elements
                L[suffixStart], L[i] = L[i], L[suffixStart]
        suffixStart += 1
