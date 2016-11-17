import heapq

input = []
q1 = []
q2 = []
median = -1
start_value = 1983
median_sum = 0

def get_value(n):
    global input
    return (n * input[1] + input[2]) % 20090711


def run():
    global input, q1, q2, median, median_sum, start_value
    input = []
    q1 = []
    q2 = []
    input_data = raw_input("")
    for n in input_data.split():
        input.append(int(n))
    #print input

    start_value = 1983
    median = 1983
    median_sum = 1983
    for _ in range(1, input[0]):
        median_sum += solve()
        #print median, median_sum
    median_sum %= 20090711
    print median_sum

def solve():
    global median, start_value

    start_value = get_value(start_value) 
    if(start_value > median):
        heapq.heappush(q2, start_value)
    else:
        heapq.heappush(q1, (-1)* start_value)

    if(abs(len(q2) - len(q1)) >= 2):
        if(len(q2) > len(q1)):
            heapq.heappush(q1, (-1)* median)
            median = heapq.heappop(q2)
        else:
            heapq.heappush(q2, median)
            median = abs(heapq.heappop(q1))
    elif len(q1) - len(q2) == 1:
        heapq.heappush(q2, median)
        median = abs(heapq.heappop(q1))
    return median 

cases = int(raw_input(""))
for _ in range(cases):
    run()
