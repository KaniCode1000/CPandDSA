t = int(input())
while t != 0:
    t-=1
    n = int(input())
    a = input()
    m = int(input())
    b = input()
    c = input()
    prefix = ''
    suffix = ''
    for i in range(m):
        if c[i] == 'D':
            suffix += b[i]
        else:
            prefix += b[i]
    print(prefix[::-1]+a+suffix)
