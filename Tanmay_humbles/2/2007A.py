t = int(input())
while t!=0:
    t-=1
    l,r = map(int,input().split())
    tot = 0
    for i in range(l+((l+1)%2),r+1,4):
        if r-i >= 2:
            tot += 1
    print(tot)
