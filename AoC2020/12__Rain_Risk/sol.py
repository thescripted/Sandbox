with open("test.txt") as file:
    data = file.read().split('\n')[:-1]

print(data)
