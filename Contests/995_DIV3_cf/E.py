t = int(input())
for _ in range(t):
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    for i in range(n):
        b[i] = b[i]-a[i]
    b.sort(reverse = True)
    total = 0
    for i in range(k):
        total += b[k]
    print(sum(a)+total,"meow")