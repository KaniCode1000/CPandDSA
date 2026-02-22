import math
t = int(input())
while (t!=0):
    t -= 1
    n = int(input())
    value = 10
    z = 1
    tx = 0
    ans = []
    while (z <= int(math.log(n,10))):
        if n % (value+1) == 0:
           tx += 1
           ans.append(n//(value+1))
        z += 1
        value *= 10
    print(tx)
    if tx > 0:
        for i in range(tx):
            print(ans[tx-i-1],end = ' ')
