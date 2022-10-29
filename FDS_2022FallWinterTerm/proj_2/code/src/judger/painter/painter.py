import matplotlib.pyplot as plt

def foo():
    # read in the data
    filename = input()
    fin = open(filename + ".in", "r")
    fout = open(filename + ".out", "r")
    # T test cases
    T = int(fin.readline())
    id = 0
    while T != 0:
        id = id + 1
        T -= 1
        # initialization
        xA = []; yA = []; xB = []; yB = []
        # Number of origin points.
        numOriA = int(fin.readline())
        for i in range(numOriA):
            line = fin.readline().split()
            xA.append( float(line[0]) )
            yA.append( float(line[1]) )
        # Link the tail and the head and to be a close polygon.
        xA.append(xA[0])
        yA.append(yA[0])

        numOriB = int(fin.readline())
        for i in range(numOriB):
            line = fin.readline().split()
            xB.append( float(line[0]) )
            yB.append( float(line[1]) )
        # Link the tail and the head and to be a close polygon.
        xB.append(xB[0])
        yB.append(yB[0])

        # Begin drawing!
            # Get Current Axes
        ax = plt.gca()
        # Make sure x : y = 1 : 1.
        ax.set_aspect(1)
        # Polygon A
        for i in range(numOriA):
            plt.plot([xA[i], xA[i+1]], [yA[i], yA[i+1]], color=(0.7, 0.95, 0.9), linestyle = 'dashed', linewidth=1.5)       
            plt.scatter(xA[i], yA[i], color=(0.7, 0.95, 0.9))  
        # Polygon B
        for i in range(numOriB):
            plt.plot([xB[i], xB[i+1]], [yB[i], yB[i+1]], color=(0.9, 0.95, 0.7), linestyle = 'dashed', linewidth=1.5)
            plt.scatter(xB[i], yB[i], color=(0.9, 0.95, 0.7))  
          
        f = fout
        
        numOut = int(f.readline())
        xxA = []; yyA = []; xxB = []; yyB = [] # Dirty variable name! But I am tired!
        for i in range(numOut):
            line = f.readline().split()
            ia = int(line[0]) - 1
            ib = int(line[1]) - 1
            xxA.append(xA[ia])
            yyA.append(yA[ia])
            xxB.append(xB[ib])
            yyB.append(yB[ib])
        # Link the tail and the head and to be a close polygon.
        if len(xxA) > 0:
            xxA.append(xxA[0])
            yyA.append(yyA[0])
        if len(yyA) > 0:
            xxB.append(xxB[0])
            yyB.append(yyB[0])

        # Begin drawing!
        for i in range(numOut):
            plt.plot([xxA[i], xxA[i+1]], [yyA[i], yyA[i+1]], color=(0.6*i/numOut+0.3, 0.95, 0.9-0.6*i/numOut), linewidth=2.5)
            plt.plot([xxB[i], xxB[i+1]], [yyB[i], yyB[i+1]], color=(0.6*i/numOut+0.3, 0.95, 0.9-0.6*i/numOut), linewidth=2.5)
            plt.plot([xxA[i], xxB[i]], [yyA[i], yyB[i]], color=(0.6*i/numOut+0.3, 0.95, 0.9-0.6*i/numOut), linestyle = 'dashed', linewidth=0.5)
        
        # plt.show()
        path = './results_tmp/' + str(id) + '.png'
        print(path)
        plt.savefig(path)

    fin.close()
    fout.close()

foo()
