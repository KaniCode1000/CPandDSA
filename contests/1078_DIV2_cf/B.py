t = int(input())
while (t!=0):
    t-=1
    n,x,y = map(int,input().split())
    diff = x-y
    a = list(map(int,input().split()))
    a.sort(key= lambda ai: diff*(ai//x) + (ai%x))
    total = 0
    for i in a:
        total += i - (diff*(i//x) + (i%x))
    total += diff*(a[-1]//x) + a[-1]%x
    print(total)
