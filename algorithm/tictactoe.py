cached_map = {}
data = [0,0,0,0,0,0,0,0,0]

def check_who_wins(data):
    if data[0] and data[0] == data[1] and data[1] == data[2]:
        return data[0]
    if data[3] and data[3] == data[4] and data[4] == data[5]:
        return data[3]
    if data[6] and data[6] == data[7] and data[7] == data[8]:
        return data[6]
    if data[0] and data[0] == data[3] and data[3] == data[6]:
        return data[0]
    if data[1] and data[1] == data[4] and data[4] == data[7]:
        return data[1]
    if data[2] and data[2] == data[5] and data[5] == data[8]:
        return data[2]
    if data[0] and data[0] == data[4] and data[4] == data[8]:
        return data[0]
    if data[2] and data[2] == data[4] and data[4] == data[6]:
        return data[2]
    return 0

def is_leaf(data):
    for i in data:
        if i == 0:
            return False
    return True

def make_cached_map(data, turn):
    global cached_map
    if is_leaf(data):
        win = check_who_wins(data)
        cached_map[genKey(data)] = win
        return win
    if genKey(data) in cached_map.keys():
        return cached_map[genKey(data)]
    win = -1
    if turn:
        for i in range(0, 9):
            if data[i] == 0 and not win == 1:
                data[i] = 1
                ret = make_cached_map(data, False)
                data[i] = 0
                if ret == 1:
                    win = 1
                elif ret == 0:
                    win = 0
                elif ret == 2 and not win == 0:
                    win = 2
    else:
        for i in range(0, 9):
            if data[i] == 0 and not win == 2:
                data[i] = 2
                ret = make_cached_map(data, True)
                data[i] = 0
                if ret == 2:
                    win = 2
                elif ret == 0:
                    win = 0
                elif ret == 1 and not win == 0:
                    win = 1
    cached_map[genKey(data)] = win
    return win

def genKey(x):
    key = 0
    pos = 0
    for i in x:
        key += pow(3,pos)* i
        pos += 1
    return key

def parse(x):
    global data
    for c in x:
        if c == '.':
            data.append(0)
        elif c == 'x':
            data.append(1)
        elif c == 'o':
            data.append(2)

num_cases = int(raw_input(""))
make_cached_map(data, True)
print cached_map
for _ in range(num_cases):
    data = []
    i1=raw_input("")
    parse(i1)
    i2=raw_input("")
    parse(i2)
    i3=raw_input("")
    parse(i3)
    val = 0
    if genKey(data) in cached_map.keys():
        val = cached_map[genKey(data)]
    if val == 1:
        print "x"
    elif val == 2:
        print "o"
    elif val == 0:
        print "TIE"
    else:
        print "TIE"


