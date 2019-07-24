def gcdIter(a, b):
    '''
    a, b: positive integers
    
    returns: a positive integer, the greatest common divisor of a & b.
    '''
    if a<b:
        large = b
        small = a
    else:
        large = a
        small = b
    
    for x in range(small, 0, -1):
        if large % x == 0 and small % x == 0:
            print(x)
            break

gcdIter(35, 77)