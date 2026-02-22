t = int(input())
while (t!=0):
    t -= 1
    x,y = list(map(int,input().split()))
    if (x == 0 and y == 0):
        print(f"{0} {0}")
        continue
    xstr = bin(x)[2:]
    ystr = bin(y)[2:]

    xlen = len(xstr)
    ylen = len(ystr)

    xval = 2**(xlen)
    yval = 2**(ylen)

    if x > y:
        p = x
        xl = list(map(int,xstr))
        yl = list(map(int,ystr))
        i = -1
        value = 1
        q = 0
        while (i != -1 - ylen):
            if (xl[i] == 0):
                yl[i] = 1
                q += value
            else:
                yl[i] = 0
            value *= 2
            i -= 1

        if (yval > x or (xlen > ylen and (xl[-ylen-1]) == 0)) and yval-y < abs(q-y):
            q = yval
    else:
        q = y
        xl = list(map(int,xstr))
        yl = list(map(int,ystr))
        i = -1
        value = 1
        p = 0
        while (i != -1 - xlen):
            if (yl[i] == 0):
                xl[i] = 1
                p += value
            else:
                xl[i] = 0
            value *= 2
            i -= 1

        if (xval > y or (ylen > xlen and (yl[-xlen-1]) == 0)) and xval-x < abs(p-x):
            p = xval


    print(f"{p} {q}")