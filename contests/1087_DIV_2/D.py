t = int(input())
while (t!=0):
    t-=1
    r,g,b = list(map(int,input().split()))
    a = [r,g,b]
    maxi = ""
    mini = ""
    maxx = max(a)
    alll = ['R','G','B']
    minn = min(a)
    a.remove(minn)
    a.remove(maxx)
    middle = a[0]
    if (r == maxx):
        maxi += 'R'
    elif (g == maxx):
        maxi += 'G'
    else:
        maxi += 'B'

    if (g == minn):
        mini += 'G'
    elif (r == minn):
        mini += 'R'
    else:
        mini += 'B'

    alll.remove(mini)
    alll.remove(maxi)
    mid = alll[0]
    combo = maxi+mid+maxi+mini
    ans = ""
    if (maxx == minn):
        ans +=     
    if (2*(minn) > maxx):
        ans = combo*(maxx//2) + (maxx%2)*maxi
        combination = mid+mini
        middle -= maxx//2
        minn -= maxx//2
        ans += (combination)*minn
    else:
        ans = combo*(minn)
        maxx -= minn*2
        middle -= minn
        if maxx < middle:
            ans += (mid + maxi)*maxx + mid
        elif maxx == middle:
            ans += (mid + maxi)*maxx
        else:
            ans += (maxi+mid)*middle + maxi
    print(ans)
