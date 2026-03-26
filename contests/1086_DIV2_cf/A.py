t = int(input())
while (t!=0):
    t -= 1
    ans = "YES"
    n = int(input())
    x = dict()
    for i in range(n):
        l = list(map(int,input().split()))
        for j in l:
            if j in x:
                x[j] += 1
                if x[j] > n*n - n:
                    ans = "NO"
            else:
                x[j] = 1
    if n == 1:
        print("NO")
        continue
    print(ans)