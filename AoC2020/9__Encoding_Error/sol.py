with open("input.txt") as file:
    data = [int(item) for item in file.read().split('\n')[:-1]]


def twosum(source, target):
    source = sorted(source)
    i = 0
    j = len(source) - 1
    while i < j:
        value = source[i] + source[j]
        if value > target:
            j -= 1
        elif value < target:
            i += 1
        else:
            return True
    return False


preamble = 25
goal = 0
for i in range(preamble, len(data)):
    source = data[i - preamble:i]
    if twosum(source, data[i]) is False:
        goal = data[i]
        print(data[i])

# part two
print("Goal: " + str(goal))
for i in range(len(data) - 1):
    total_sum = data[i]
    for j in range(i + 1, len(data)):
        total_sum += data[j]
        if total_sum > goal:
            break
        if total_sum == goal:
            res = data[i:j+1]
            print("Solution set ", res)
            print("Sum: ", sum(res))
            res = sorted(res)
            print("Result: ", res[0] + res[-1])
