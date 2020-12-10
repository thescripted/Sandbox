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
