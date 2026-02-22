t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    ans = 0
    for i in range(0,n-1):
        if a[i] > b[i+1]:
            ans += a[i]-b[i+1]
    ans += a[n-1]
    print(ans)

