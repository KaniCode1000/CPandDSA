t = int(input())
while (t != 0):
    t -= 1
    n = int(input())
    arr = [n//2+1]
    for i in range(1,n):
        arr.append(arr[i-1]+(i*((-1)**i)))
    for i in arr:
        print(i,end=' ')
    print()