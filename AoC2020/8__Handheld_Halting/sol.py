import re
with open("input.txt") as file:
    lines = [line.rstrip('\n') for line in file.read().split('\n')
             if len(line) > 0]
last = len(lines) - 1
step = 0
acc = 0
detected = set()


def parse(line):
    op, val = re.findall(r'(.+?) ([+-]\d+)', line)[0]
    return op, int(val)


def op_reduce(op, val):
    if op == 'nop':
        return 1, 0
    if op == 'acc':
        return 1, val
    if op == 'jmp':
        return val, 0


while True:
    current_line = lines[step]
    if step in detected:
        break
    if step == last:
        print(acc)
    detected.add(step)
    operation, value = parse(current_line)
    jump, accum = op_reduce(operation, value)
    step += jump
    acc += accum


def solve(lines):
    step = 0
    acc = 0
    detect = set()
    while True:
        current = lines[step]
        if step in detect:
            return None
        detect.add(step)
        op, val = parse(current)
        jmp, accum = op_reduce(op, val)
        acc += accum
        if step == len(lines) - 1:
            return acc
        step += jmp


# Part 2
for i in range(len(lines)):
    prog = lines[:]
    op, val = parse(prog[i])
    if op == 'nop':
        prog[i] = prog[i].replace('nop', 'jmp')
    elif op == 'jmp':
        prog[i] = prog[i].replace('jmp', 'nop')
    num = solve(prog)
    if num is not None:
        print(num)
