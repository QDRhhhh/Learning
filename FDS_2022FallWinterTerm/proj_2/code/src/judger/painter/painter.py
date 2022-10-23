import matplotlib.pyplot as plt
import numpy as np
import warnings
import copy

def foo():
    warnings.filterwarnings('ignore')
    # read in the data
    filename = input()
    fin = open(filename + ".in", "r")
    finfo = open(filename + ".info", "r")
    fout = open(filename + ".out", "r")
    # T test cases
    T = int(fin.readline())
    while T != 0:
        T -= 1
        # initialization
        xA = []; yA = []; xB = []; yB = []
        # Number of origin points.
        numOri = int(fin.readline())
        for i in range(numOri):
            line = fin.readline().split()
            xA.append( float(line[0]) )
            yA.append( float(line[1]) )
        # Link the tail and the head and to be a close polygon.
        xA.append(xA[0])
        yA.append(yA[0])

        numOri = int(fin.readline())
        for i in range(numOri):
            line = fin.readline().split()
            xB.append( float(line[0]) )
            yB.append( float(line[1]) )
        # Link the tail and the head and to be a close polygon.
        xB.append(xB[0])
        yB.append(yB[0])

        # Begin drawing!
        for subIdx in [121, 122]:
            plt.subplot(subIdx)
            # Get Current Axes
            ax = plt.gca()
            # Make sure x : y = 1 : 1.
            ax.set_aspect(1)        
            for i in range(numOri):
                # Polygon A
                plt.plot([xA[i], xA[i+1]], [yA[i], yA[i+1]], color=(0.4, 0.85, 0.9), linestyle = 'dashed', linewidth=2)       
                plt.scatter(xA[i], yA[i], color=(0.4, 0.85, 0.9))    
                # Polygon B
                plt.plot([xB[i], xB[i+1]], [yB[i], yB[i+1]], color=(0.9, 0.85, 0.4), linestyle = 'dashed', linewidth=2)
                plt.scatter(xB[i], yB[i], color=(0.9, 0.85, 0.4))  
          
            if subIdx == 121 :
                f = fout
            else :
                f = finfo
                
            numOut = int(f.readline())
            xxA = []; yyA = []; xxB = []; yyB = [] # Dirty variable name! But I am tired!
            for i in range(numOut):
                line = f.readline().split()
                ia = int(line[0])
                ib = int(line[1])
                xxA.append(xA[ia])
                yyA.append(yA[ia])
                xxB.append(xB[ib])
                yyB.append(yB[ib])
            # Link the tail and the head and to be a close polygon.
            xxA.append(xxA[0])
            yyA.append(yyA[0])
            xxB.append(xxB[0])
            yyB.append(yyB[0])

            # Begin drawing!
            plt.subplot(subIdx)
            for i in range(numOut):
                plt.plot([xxA[i], xxA[i+1]], [yyA[i], yyA[i+1]], color=(0.6*i/numOut+0.3, 0.95, 0.9-0.6*i/numOut), linewidth=2.5)
                plt.plot([xxB[i], xxB[i+1]], [yyB[i], yyB[i+1]], color=(0.6*i/numOut+0.3, 0.95, 0.9-0.6*i/numOut), linewidth=2.5)
                plt.plot([xxA[i], xxB[i]], [yyA[i], yyB[i]], color=(0.6*i/numOut+0.3, 0.95, 0.9-0.6*i/numOut), linestyle = 'dashed', linewidth=0.5)

        
        plt.show()

    fin.close()
    finfo.close()
    fout.close()
foo()