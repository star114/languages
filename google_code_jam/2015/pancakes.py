import heapq

def getMinMinute(p):
    maxval = heapq.heappop(p)

# raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
    d = int(raw_input())
    p = []
    for s in raw_input().split(" "):
        heapq.heappush(p, int(s))
    print "Case #{}: {}".format(i, getMinMinute(p))
    # check out .format's specification for more formatting options
