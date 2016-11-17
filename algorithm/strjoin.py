def calc(D):
    if len(D) == 2:
        return D[0] + D[1]
    intermediate = D.pop(0) + D.pop(0)
    D.append(intermediate)
    D.sort()
    return intermediate + calc(D)
def run():
    N = int(raw_input(""))
    D = [int(x) for x in raw_input("").split()]
    D.sort()
    print calc(D)
        
cases = int(raw_input(""))
for _ in range(cases):
    run()
