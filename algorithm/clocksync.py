status_change_rule = {0:[0,1,2], 1:[3,7,9,11], 2:[4,10,14,15], 3:[0,4,5,6,7], 4:[6,7,8,10,12],
        5:[0,2,14,15], 6:[3,14,15], 7:[4,5,7,14,15], 8:[1,2,3,4,5], 9:[3,4,5,9,13]}
initial_status = []

def check_status():
    global initial_status
    for i in range(16):
        if (initial_status[i]%4) != 0:
            return False
    return True

def apply_change_rule(index):
    global initial_status
    for i in status_change_rule[index]:
        initial_status[i] += 1

def clock_sync():
    global initial_status
    initial_status = []
    timeofclocks = raw_input ("Current status of clocks (12 clocks):")
    for time in timeofclocks.split():
        initial_status.append((int(time)/3)%4)
#    print initial_status
    min_val = 10000
    for i0 in range(4):
        for i1 in range(4):
            for i2 in range(4):
                for i3 in range(4):
                    for i4 in range(4):
                        for i5 in range(4):
                            for i6 in range(4):
                                for i7 in range(4):
                                    for i8 in range(4):
                                        for i9 in range(4):
                                            temp_min = i0 + i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9
                                            if temp_min > min_val:
                                                break
                                            if (temp_min < min_val) & check_status() :
                                                min_val = temp_min
                                            apply_change_rule(9)
                                        apply_change_rule(8)
                                    apply_change_rule(7)
                                apply_change_rule(6)
                            apply_change_rule(5)
                        apply_change_rule(4)
                    apply_change_rule(3)
                apply_change_rule(2)
            apply_change_rule(1)
        apply_change_rule(0)
    print min_val
cases = int(raw_input ("Number of test cases:"))
for _ in range(cases):
    clock_sync()
