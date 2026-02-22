t = int(input())
while (t):
    t -= 1
    n = int(input())
    p = list(map(lambda x: n+1 - int(x),input().split()))
    print(*p)