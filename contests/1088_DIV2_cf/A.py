t = int(input())
while (t!=0):
    t-=1
    n = int(input())
    arr = map(int,input().split())
    if n == 1:
        print(1)
    else:
        for i in range(n):
            print(2,end = ' ')
        print()