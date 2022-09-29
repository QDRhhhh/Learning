import matplotlib.pyplot as plt
import numpy as np

def foo():
    # read in the data
    data = ""
    with open("output.txt", "r") as f:
        data = f.read()
    
    data = data.split(' \n')
    arrN = [5, 10, 15, 20, 25, 30, 35, 40, 50, 60, 80, 100]
    arrT = np.zeros((3, len(arrN)), dtype=np.float)
    arrTT = np.zeros((3, len(arrN)), dtype=np.float)

    for itr in range(len(arrN)):
        for met in range(3):
            s = data[3*itr+met].split(' ')
            print(s)
            arrTT[met][itr] = float(s[0])
            arrT[met][itr] = float(s[1])

    # draw picture of N3 vs N4
    plt.figure(figsize=(3, 5))
    plt.xlim(5, 100)
    plt.xlabel("N")
    plt.ylim(0, arrT[1][len(arrN)-1])
    plt.ylabel("run_time/s")
    plt.plot(arrN, arrT[0], color='g', marker='o', label='N3')
    plt.plot(arrN, arrT[1], color='r', marker='o', label='N4')
    plt.legend()
    plt.savefig("N3vsN4.jpg")

    # draw picture of N3 vs N4 vs N6
    plt.figure(figsize=(4, 8))
    plt.xlim(5, 100)
    plt.xlabel("N")
    plt.ylim(0, 0.5*(arrT[2][len(arrN)-1]+arrT[2][len(arrN)-2]))
    plt.ylabel("run_time/s")
    plt.plot(arrN, arrT[0], color='g', marker='o', label='N3')
    plt.plot(arrN, arrT[1], color='r', marker='o', label='N4')
    plt.plot(arrN, arrT[2], color='b', marker='o', label='N6')
    plt.legend()
    plt.savefig("N3vsN4vsN6.jpg")

    plt.show()

foo()