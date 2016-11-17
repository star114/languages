# raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
    row = int(raw_input())
    data = [0 for _ in range(4)]
    for j in range(1,5):
        if j+1 == row:
            data = [int(s) for s in raw_input().split(" ")]  # read a list of integers, 2 in this case
        else:
            raw_input()
    row_after = int(raw_input())
    data_after = [0 for _ in range(4)]
    for k in range(1,5):
        if k+1 == row_after:
            data_after = [int(s) for s in raw_input().split(" ")]
        else:
            raw_input()
    found = False
    foundmore = False
    result = 0
    for c in data_after:
        if c in data:
            if found:
                foundmore = True
            else:
                found = True
                result = c

    if foundmore:
        print "Case #{}: {}".format(i, "Bad magician!")
    elif found:
        print "Case #{}: {}".format(i, result)
    else:
        print "Case #{}: {}".format(i, "Volunteer cheated!")
