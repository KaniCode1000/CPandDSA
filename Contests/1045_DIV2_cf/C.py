t = int(input())
while t!=0:
    t-=1
    n = int(input())
    arr = list(map(int,input().split()))
    numops = 0
    if arr[0] > arr[1]:
        numops += arr[0]-arr[1]
        arr[0] = arr[1]
    for i in range(1,n,2):
        if i == n-1:
            numops += max(0,arr[i-1]-arr[i])
            continue
        if arr[i] < arr[i+1]+arr[i-1]:
            numops +=  arr[i+1]+arr[i-1]-arr[i]
            arr[i+1] = max(arr[i] - arr[i-1],0)
    print(numops)