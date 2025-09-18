t = int(input())
while (t!=0):
    t-=1
    n,k = map(int,input().split())
    arr = list(map(int,input().split()))
    if k == 2:
        for i in arr:
            if i%3 == 0:
                print(i,end=' ')
            elif i%3 == 1:
                print(i+2,end=' ')
            else:
                print(i+4,end=' ')
    elif k%2 == 1:
        for i in arr:
            if i%2 == 1:
                print(i+k,end=' ')
            else:
                print(i,end=' ')
    else:
        for i in arr:
            p = i%k
            print((k-1-p)*k + p,end=' ')
    print()