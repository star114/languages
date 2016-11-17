def calc(M, E, N):
    temp = []
    for i in range(N):
        temp.append((E[i], M[i]))
    temp.sort(reverse=True)
    total_heat = 0
    total = 0
    for data in temp:
        total_heat += data[1]
        total = max(total, total_heat+data[0])
    print total    

def run():
    num = int(raw_input(""))
    M = raw_input("")
    M = [int(x) for x in M.split()]
    E = raw_input("")
    E = [int(x) for x in E.split()]
    calc(M,E,num)


T = int(raw_input(""))
for _ in range(T):
    run()
