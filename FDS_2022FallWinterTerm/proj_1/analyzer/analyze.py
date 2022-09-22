import matplotlib.pyplot as plt
import numpy as np

def foo():
    # read in the data
    data = ""
    with open("./../output.txt", "rt") as f:
        data = f.read()
    data = data.split(' \n')
    arrN = [5, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
    arrT = np.zeros((3, len(arrN)), dtype=np.float)
    arrA = np.zeros((3, len(arrN)), dtype=np.int)

    for itr in range(len(arrN)):
        for met in range(3):
            s = data[3*itr+met].split(' ')
            print(s)
            arrA[met][itr] = int(s[0])
            arrT[met][itr] = float(s[1])

    # draw picture of N3 vs N4
    plt.figure(figsize=(4, 8))
    plt.xlim(5, 100)
    plt.xlabel("N")
    plt.ylim(0, 0.1)
    plt.ylabel("run_time/s")
    plt.plot(arrN, arrT[0], color='g', marker='o', label='N3')
    plt.plot(arrN, arrT[1], color='r', marker='o', label='N4')
    plt.legend()
    plt.savefig("N3vsN4.jpg")

    # draw picture of N3 vs N4 vs N6
    plt.figure(figsize=(4, 8))
    plt.xlim(5, 100)
    plt.xlabel("N")
    plt.ylim(0, 10)
    plt.ylabel("run_time/s")
    plt.plot(arrN, arrT[0], color='g', marker='o', label='N3')
    plt.plot(arrN, arrT[1], color='r', marker='o', label='N4')
    plt.plot(arrN, arrT[2], color='b', marker='o', label='N6')
    plt.legend()
    plt.savefig("N3vsN4vsN6.jpg")

    plt.show()

foo()