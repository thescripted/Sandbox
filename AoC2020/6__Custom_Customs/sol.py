# Part One is in comments.
with open("input.txt") as file:
    # data = [line.replace("\n", "").replace(" ", "")
    #        for line in file.read().split("\n\n")]
    data = [line.rstrip("\n").replace(" ", "").split("\n")
            for line in file.read().split("\n\n")]


total = 0
for item in data:
    common_set = set(item[0])
    for i, next_item in enumerate(item):
        if i == 0:
            continue
        common_set = common_set.intersection(next_item)
    print(common_set)
    total += len(common_set)

print(total)

# item_set = set()
# for char in item:
#     item_set.add(char)
# total += len(item_set)

# print(total)
