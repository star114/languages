cached_data = [[-1]*100 for i in range(100)]
for i in range(100):
    cached_data[0][i] = 1

def solve_2(remains, above_line):
    global cached_data
    if cached_data[remains][above_line] != -1:
       return cached_data[remains][above_line]
    result = 0
    for i in range(remains):
        result += (i + above_line) * solve_2(remains-i-1, i+1)
        result %= 10000000
    cached_data[remains][above_line] = result
    return result

def solve(n):
    result = 0
    for i in range(n):
        result += solve_2(n-i-1, i+1)
        result %= 10000000
    return result

cases = int(raw_input(""))

for _ in range(cases):
    n = int(raw_input(""))
    print solve(n)
