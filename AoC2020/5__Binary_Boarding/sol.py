import math
with open("input.txt") as file:
    boarding_pass = [line.rstrip('\n') for line in file.read().split('\n')]


def binary_search(arr):
    low = 0
    space = 127
    last_letter = None
    for letter in arr:
        last_letter = letter
        if letter == 'F':
            space = low + math.floor((space * 1.0 - low) / 2)
        elif letter == 'B':
            low = low + math.ceil((space * 1.0 - low) / 2)
    if last_letter == 'F':
        return low
    else:
        return space


def binary_csearch(arr):
    low = 0
    space = 7
    last_letter = None
    for letter in arr:
        last_letter = letter
        if letter == 'L':
            space = low + math.floor((space * 1.0 - low) / 2)
        elif letter == 'R':
            low = low + math.ceil((space * 1.0 - low) / 2)
    if last_letter == 'L':
        return low
    else:
        return space


highest = 0
seat_arr = []
for bpass in boarding_pass:
    # dont read empty lines
    if len(bpass) < 1:
        continue

    row = binary_search(bpass[0:7])
    col = binary_csearch(bpass[7:10])
    res = (row * 8) + col
    seat_arr.append(res)
    highest = max(highest, res)

# part 1
print(highest)

# part 2
seat_arr = sorted(seat_arr)
for i in range(1, len(seat_arr)):
    if int(seat_arr[i - 1]) != int(seat_arr[i]) - 1:
        print(seat_arr[i - 1] + 1)
