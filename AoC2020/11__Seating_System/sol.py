with open("input.txt") as file:
    data = [list(line) for line in file.read().split('\n')[:-1]]


def _count_adj(data, i, j):
    space = [(i - 1, j), (i - 1, j + 1),
             (i, j + 1), (i + 1, j + 1),
             (i + 1, j), (i + 1, j - 1),
             (i, j - 1), (i - 1, j - 1)]
    row = len(data)
    col = len(data[0])
    total = 0
    for row_i, col_j in space:
        if row_i < 0 or row_i >= row or col_j < 0 or col_j >= col:
            continue
        if data[row_i][col_j] == '#':
            total += 1
    return total


def _count_occ(data):
    count = 0
    for i in range(len(data)):
        for j in range(len(data[0])):
            if data[i][j] == '#':
                count += 1
    return count


prev_stab = -1
while True:
    copy = [[0 for _ in range(len(data[0]))] for _ in range(len(data))]
    curr_stab = 0
    for i in range(len(data)):
        for j in range(len(data[i])):
            copy[i][j] = data[i][j]
            if data[i][j] == '.':
                continue
            count = _count_adj(data, i, j)
            if count == 0:
                copy[i][j] = '#'
            if count >= 4:
                copy[i][j] = 'L'
    curr_stab = _count_occ(copy)
    if curr_stab == prev_stab:
        break
    data = copy
    prev_stab = curr_stab
print(curr_stab)
