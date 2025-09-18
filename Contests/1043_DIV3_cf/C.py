import math
t = int(input())
while (t!=0):
    t-=1
    n,k = map(int,input().split())
    cost = 0
    deals = 0
    totpower = int(math.log(n,3)//1)
    ans = [0]*(totpower+1)
    for i in range(totpower+1):
        f = n%3
        n//=3
        ans[totpower-i] = f
        deals += f
    # print(ans,deals)
    if deals > k:
        print(-1)
    else:
        optimization_deals = (k - deals)//2
        for i in range(totpower):
            if optimization_deals > 0:
                # print(optimization_deals)
                ans[i+1] = min(3*ans[i]+ans[i+1],optimization_deals*3+ans[i+1])
                temp = ans[i]
                ans[i] = max(ans[i]-optimization_deals,0)
                optimization_deals = max(0,optimization_deals-temp)
        value = 1
        for i in range(totpower+1):
            cost += (3*value + (i*(value//3)))*ans[totpower-i]
            value*=3
        print(int(cost))

    