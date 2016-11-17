def get_time(C, F, X):
    cur_time = X / 2
    min_time = cur_time
    n = 1
    sn = 0
    while cur_time >= 0.0000001:
        cur_time = X/(2+n*F)
        sn = sn + C/(2+(n-1)*F)
        time = cur_time +  sn
        if time > min_time:
            break
        else:
            min_time = time
        n += 1
    return min_time

# raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
    C, F, X = [float(s) for s in raw_input().split(" ")]  # read a list of integers, 2 in this case
    print "Case #{}: {}".format(i, get_time(C,F,X))
    # check out .format's specification for more formatting options
