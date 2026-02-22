t = int(input())
while (t!= 0):
    t-=1
    n,w = list(map(int,input().split()))
    print(n%w + (n//w)*(w-1))