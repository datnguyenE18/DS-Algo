def isMonotonous(sequence):
    check = all(x < y for x, y in zip(sequence, sequence[1:]))
    if check == False and sequence[-1] < 0:
        return True
    return check