t = int(input())
for _ in range(t):
    n = int(input())
    arr = [-1 if i % 2 == 0 else 3 for i in range(n-1)]
    if n%2 == 0:
        arr.append(2)
    else:
        arr.append(-1)
    for i in arr:
        print(f"{i} ",end = '')
    print()
    