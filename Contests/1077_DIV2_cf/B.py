import math

t = int(input())
while (t!=0):
    t-= 1
    n = int(input())
    l = list(map(int,list(input())))
    total = 0
    if n == 1:
        print(1)
        continue
    for i in range(n):
        if i == 0 and l[i] == 1:
            l[1] = 2
            l[0] = 2
            total += 1
        elif i == n-1 and l[i] == 1:
            l[n-2] = 2
            l[n-1] = 2
            total += 1
        elif l[i] == 1:
            total += 1
            l[i-1] = 2
            l[i] = 2
            l[i+1] = 2
    i = 0
    count = 0
    while i<n:
        if l[i] == 2:
            total += math.ceil(count/3)
            count = 0
        else:
            count += 1
        i+=1
    total += math.ceil(count/3)
    print(total)