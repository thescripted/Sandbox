with open("input.txt") as file:
    data = [int(i) for i in file.read().split('\n')[:-1]]

data.append(0)
data.append(max(data) + 3)
data = sorted(data)
ones = 0
threes = 0
for i in range(1, len(data)):
    diff = data[i] - data[i-1]
    if diff == 1:
        ones += 1
    if diff == 3:
        threes += 1
print(ones * threes)

# part two:
memo = {}


def dp(k):
    if data[k] == max(data):
        return 1
    if k in memo:
        return memo[k]
    ans = 0
    for i in range(k + 1, len(data)):
        if data[i] - data[k] <= 3:
            ans += dp(i)
    memo[k] = ans
    return ans


print(dp(0))

# Without Recursion:


def valid_set(data, start, dp_arr):
    total = dp_arr[start + 3]
    for i in range(start, start + 3):
        if i < 0:
            continue
        if data[start + 3] - data[i] <= 3:
            total += dp_arr[i]
    return total


dp_arr = [0 for _ in range(len(data))]
dp_arr[0] = 1
for i in range(len(data)):
    dp_arr[i] = valid_set(data, i-3, dp_arr)
print(dp_arr[-1])
