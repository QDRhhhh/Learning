import matplotlib.pyplot as plt
import numpy as np
import warnings

def foo():
    warnings.filterwarnings('ignore')
    # read in the data
    with open("txt", "r") as f:
        T = int(f.readline())
        while T != 0:
            xA = []
            yA = []
            xB = []
            yB = []
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

            for i in range(num):
                plt.scatter(xA[i], yA[i], color=(0.1, (i+2)/(num+5), (i+2)/(num+5)), )    
                plt.plot([xA[i], xA[i+1]], [yA[i], yA[i+1]], color=(0.1, (i+2)/(num+5), (i+2)/(num+5)))       
            plt.show()
foo()