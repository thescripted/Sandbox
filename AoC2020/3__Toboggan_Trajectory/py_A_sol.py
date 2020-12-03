inputs = [(1, 1), (3, 1), (5, 1), (7, 1), (1, 2)]
total = 1
for i in inputs:
    with open("input.txt") as file:
        v = [x for x in file.read().split("\n")[::i[1]]]

    trees = 0
    x = 0
    for y in v:
        if len(y) == 0:
            break
        print(y)
        trees += (y[x % len(v[0])] == "#")
        x += i[0]
    total *= trees

print("Number of trees: " + str(total))
