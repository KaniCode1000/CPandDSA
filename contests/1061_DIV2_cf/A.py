t = int(input())
while (t):
    t -= 1
    n = int(input())
    total = 0
    while True:
        if n <= 2:
            break
        total += n//3
        n = n//3 + (n%3)
    print(total)

        
