import math

def solve(N, M, P):
    tmp = (12+0.01*P)/12
    po = math.pow(tmp, M)
    result = N*po / ((1-po)/(1-tmp))
    return result

cases = int(raw_input(""))

for _ in range(cases):
    input = raw_input("")
    c = input.split()
    N = float(c[0])
    M = int(c[1])
    P = float(c[2])
    print "%.9f" % solve(N, M, P)
