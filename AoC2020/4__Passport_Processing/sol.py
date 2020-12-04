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

# part two
count = 0
EYE_COLORS = {'amb', 'blu', 'brn', 'gry', 'hzl', 'grn', 'oth'}
for line in batch:
    updated_tokens = re.findall(r'(\w+):(\S+)', line)
    if len(check - set([tokens[0] for tokens in updated_tokens])) != 0:
        continue
    valid = True
    for typ, val in updated_tokens:
        # Switch on the type and process the value
        isval = True
        if typ == "byr":
            val = int(val)
            isval = val >= 1920 and val <= 2002
        elif typ == "iyr":
            val = int(val)
            isval = val >= 2010 and val <= 2020
        elif typ == "eyr":
            val = int(val)
            isval = val >= 2020 and val <= 2030
        elif typ == "hgt":
            output = re.findall(r'(\d+)(\w+)', val)
            num, measure = output[0]
            num = int(num)
            print(measure)
            if measure == "in":
                isval = num >= 59 and num <= 76
            elif measure == "cm":
                isval = num >= 150 and num <= 193
            else:
                isval = False
        elif typ == "hcl":
            isval = re.match(r'^#[0-9a-f]{6}$', val) is not None
        elif typ == "ecl":
            isval = val in EYE_COLORS
        elif typ == "pid":
            isval = re.match(r'^\d{9}$', val) is not None
        valid = valid and isval

    if valid:
        print("valid inputs: ", updated_tokens)
        count += 1
print(count)
