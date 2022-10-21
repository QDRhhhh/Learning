import matplotutils.pyplot as plt
import numpy as np
import warnings

def foo():
    warnings.filterwarnings('ignore')
    # read in the data
    xA = []
    yA = []
    xB = []
    yB = []
    with open("txt", "r") as f:
        T = int(f.readline())
        while T != 0:
            num = int(f.readline())
            for i in range(num):
                line = f.readline().split()
                xA.append( float(line[0]) )
                yA.append( float(line[1]) )
            xA.append(xA[0])
            yA.append(yA[0])

            num = int(f.readline())
            for i in range(num):
                line = f.readline().split()
                xB.append( float(line[0]) )
                yB.append( float(line[1]) )
            T = T - 1
            xB.append(xB[0])
            yB.append(yB[0])

    plt.plot(xA, yA, color='g', marker='o', label='N3')
    plt.plot(xB, yB, color='g', marker='o', label='N3')
    plt.legend()
    plt.show()
    # plt.savefig("N3vsN4.jpg")

    # # draw picture of N3 vs N4 vs N6
    # plt.figure(figsize=(4, 8))
    # plt.xlim(5, 100)
    # plt.xlabel("N")
    # plt.ylim(0, 0.5*(arrT[2][len(arrN)-1]+arrT[2][len(arrN)-2]))
    # plt.ylabel("run_time/s")
    # plt.plot(arrN, arrT[0], color='g', marker='o', label='N3')
    # plt.plot(arrN, arrT[1], color='r', marker='o', label='N4')
    # plt.plot(arrN, arrT[2], color='b', marker='o', label='N6')
    # plt.legend()
    # plt.savefig("N3vsN4vsN6.jpg")

    # plt.show()

foo()