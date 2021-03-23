tests = 1
rows, cols = 300, 300

print(tests)

from random import randint
for i in range(tests):
    print(rows, cols)
    for j in range(rows):
        for k in range(cols):
            v = randint(0, 2000000)
            print(v, end=' ')
        print()
