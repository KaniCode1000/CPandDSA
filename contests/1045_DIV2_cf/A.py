t = int(input())
while (t!=0):
    t-=1
    n,a,b = map(int,input().split())
    z = b%2
    if (n%2 == z) and (b>=a or a%2 == z):
        print("YES")
    else:
        print("NO")