line = []
DEFAULT_VAL = 99999
cachedVal1 = [[]]
cachedVal2 = [[]]
def calc(start, end, turn):
    global line, cachedVal1, cachedVal2
    if start == end:
        return line[start]*turn
    elif start > end:
        return 0
    if turn == 1:
        if cachedVal1[start][end] != DEFAULT_VAL:
            return cachedVal1[start][end]
    else:
        if cachedVal2[start][end] != DEFAULT_VAL:
            return cachedVal2[start][end]

    maxVal = max(turn*(line[start]*turn + calc(start+1, end, turn * (-1))), turn*(line[end]*turn + calc(start, end-1, turn*(-1))), turn*calc(start+2, end, turn*(-1)), turn*calc(start, end-2, turn*(-1)))

    if turn == 1:
        cachedVal1[start][end] = turn*maxVal
    else:
        cachedVal2[start][end] = turn*maxVal
    return turn*maxVal

def testcase():
    global line, cachedVal1, cachedVal2
    line = []
    lineLength = int(raw_input(""))
    cachedVal1 = [[DEFAULT_VAL]*lineLength for i in range(lineLength)]
    cachedVal2 = [[DEFAULT_VAL]*lineLength for i in range(lineLength)]
    linedata = raw_input("")
    for n in linedata.split():
        line.append(int(n))
    print calc(0, lineLength-1, 1)


testcases = int(raw_input(""))
for _ in range(testcases):
    testcase()
