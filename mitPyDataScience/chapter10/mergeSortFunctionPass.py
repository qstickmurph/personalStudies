def merge(left, right, compare):
    """Assumes left and right are sorted lists and
        compare defines an ordering on the elements.
        Returns a new sorted list containing the
        same elements as (left + right) would contain."""

    result = []
    i, j = 0, 0
    while i < len(left) and j < len(right):
        if compare(left[i], right[j]):
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    while i < len(left):
        result.append(left[i])
        i += 1

    while j < len(right):
        result.append(right[j])
        j += 1

    return result

def mergeSort(L, compare = lambda x, y: x < y):
    """Assumes L is a list, compare defines an ordering relation of L
        Returns a new sorted list with the same elements as L"""

    if len(L) < 2:
        return L[:]
    else:
        middle = len(L)/2
        left = mergeSort(L[:middle], compare)
        right = mergeSort(L[middle:], compare)
        return merge(left, right, compare)

def lastNameFirstName(name1, name2):
    arg1 = name1.split(' ')
    arg2 = name2.split(' ')
    if arg1[1] != arg2[1]:
        return arg1[1] < arg2[1]
    else:
        return arg1[0] < arg2[0]

L = ['Tom Brady', 'Eric Grimson', 'Gisele Bundchen']
newL = mergeSort(L, lastNameFirstName)
