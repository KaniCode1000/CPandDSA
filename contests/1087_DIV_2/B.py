t = int(input())
while (t!=0):
    t-= 1
    n = int(input())
    a = list(map(int,input().split()))
    for i in range(n):
        c = 0
        same = 0
        for j in range(i+1,n):
            if a[j] > a[i]:
                c += 1
            elif a[j] == a[i]:
                same += 1
        ans = max(n-i-1-c-same,c)
        print(ans,end=" ")
    print()
        
