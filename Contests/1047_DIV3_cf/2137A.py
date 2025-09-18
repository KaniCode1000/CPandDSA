t = int(input())
while (t):
    t -= 1
    k,x = map(int,input().split())
    print(x*(2**k))