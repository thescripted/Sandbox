import re
with open("input.txt") as file:
    batch = [line.rstrip("\n") for line in file.read().split("\n\n")]

check = {'eyr', 'hcl', 'hgt', 'byr', 'iyr', 'pid', 'ecl'}

count = 0
for line in batch:
    tokens = re.findall(r'(\w+):', line)
    if len(check - set(tokens)) == 0:
        count += 1

print(count)
