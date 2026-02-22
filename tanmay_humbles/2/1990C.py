t = int(input())
while t!=0:
    t -= 1
    n = int(input())
    arr = list(map(int,input().split()))
    arr2 = [0]*n
    summ = 0
    maxi = 0
    count = 0
    for i in range(n):
        summ += arr[i]
        arr2[arr[i]-1] += 1
        if arr2[arr[i]-1] > 1 and arr[i] > maxi:
            maxi = arr[i]
        arr[i] = maxi
        summ += maxi
    arr3 = [0]*n
    for i in range(n):
        arr3[arr[i]-1] += 1
    leftmost = 0
    for i in range(n):
        if arr3[arr[i]-1] > 1:
            leftmost = arr[i]
            summ += (n-i-1)*arr[i]
        else:
            summ += (n-i-1)*leftmost
    print(summ)
    
