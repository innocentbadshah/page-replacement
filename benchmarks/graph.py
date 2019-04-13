import matplotlib.pyplot as plt
import subprocess

executables = ['clock', 'lru_aging', 'lru_counter', 'lru_stack']

for executable in executables:

    bashCommand = "./build/" + executable
    output = subprocess.check_output(['bash','-c', bashCommand])

    output = output.split('\n')[:-1]

    x = []
    y = []

    for i in range(0, len(output), 2):
        elem = output[i].split(' ')[-1]
        x.append(elem)

    for i in range(1, len(output), 2):
        elem = output[i].split(' ')[-1]
        y.append(elem)

    x = map(int, x)
    y = map(int, y)

    plt.plot(x, y)
    plt.ylabel('Number of page faults')
    plt.xlabel('Number of frames')
    plt.show()

# print x,y