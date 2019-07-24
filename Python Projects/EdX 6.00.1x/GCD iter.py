def gcdIter(a, b):
    '''
    a, b: positive integers
    
    returns: a positive integer, the greatest common divisor of a & b.
    '''   
    for x in range(min(a,b), 0, -1):
        if a % x == 0 and b % x == 0:
            return x

gcdIter(35, 77)