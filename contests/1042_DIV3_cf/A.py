t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    ans = 1
    for i in range(n):
        if a[i] > b[i]:
            ans += (a[i]-b[i])
    print(ans)