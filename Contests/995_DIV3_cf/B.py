t = int(input())
for _ in range(t):
    n,a,b,c = list(map(int,input().split()))
    y = int(n/(a+b+c))
    z = y*(a+b+c)
    if z >= n:
        print(y*3)
    elif z+a>=n:
        print(y*3+1)
    elif z+a+b >= n:
        print(y*3+2)
    else:
        print(y*3+3)
