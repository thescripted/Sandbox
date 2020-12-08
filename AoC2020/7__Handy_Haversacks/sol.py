import collections
import re

with open("input.txt") as file:
    data = [line.rstrip('\n') for line in file.read().split('\n')
            if len(line) > 0]

containedin = collections.defaultdict(set)
contains = collections.defaultdict(list)
for line in data:
    print(line)
    color = re.match(r"(.+?) bags contain", line).group(1)
    for ct, innercolor in re.findall(r'(\d+?) (.+?) bags?[,.]', line):
        ct = int(ct)
        containedin[innercolor].add(color)
        contains[color].append((ct, innercolor))

holdsgold = set()


def check(color):
    for c in containedin[color]:
        holdsgold.add(c)
        check(c)


def cost(color):
    total = 0
    for ct, inner in contains[color]:
        total += ct
        total += ct * cost(inner)
    return total


check('shiny gold')
print(len(holdsgold))
print(cost('shiny gold'))
