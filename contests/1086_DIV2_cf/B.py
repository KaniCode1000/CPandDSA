t = int(input())
while (t!=0):
    t -= 1
    n,k,p,m = map(int,input().split())
    p -= 1
    a = list(map(int,input().split()))
    win = a[p]
    total = 0
    wintimes = 0
    while total <= m-win:
        if p+1 <= k:
            a.pop(p)
            p = n-1
            total += win
            wintimes += 1
            a.append(win)
        else:
            mini = a[0]
            index = 0
            for i in range(k):
                if a[i] < mini:
                    mini = a[i]
                    index = i
            a.pop(index)
            p -= 1
            a.append(mini)
            total += mini
    print(wintimes)
                    