t = int(input())
while (t != 0):
    t-=1
    n,c,k = list(map(int,input().split()))
    a = list(map(int,input().split()))
    a.sort()
    for i in a:
        if i <= c:
            v = min(k,c-i)
            c += v + i
            k -= v
        else:
            break
    print(c)

