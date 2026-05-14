import sys

mod = 676767677
limit = int(200000**0.5) + 1
is_prime = [True] * (200002 + 1)
is_prime[0] = is_prime[1] = False
for p in range(2, limit):
    if is_prime[p]:
        for i in range(p * p, limit, p):
            is_prime[i] = False
primes = [num for num in range(2, limit) if is_prime[num]]
t = int(sys.stdin.readline())
while (t!=0):
    t-=1
    total = 1
    x,y = map(int,sys.stdin.readline().split())
    diff = abs(x-y)
    if diff == 0:
        print(1)
        print("1 "*x,end = "")
        for i in range(y):
            print("-1",end = " ")
        print()
        continue
    new = diff
    for i in primes:
        if i*i > new:
            break
        if new%i == 0:
            divc = 1
            while new % i == 0:
                new //=i
                divc += 1
            total *= divc
            total %= mod
    if new > 1:
        total *= 2
        total %= mod
        
    print(int(total))
    for i in range(x):
        print("1",end = " ")
    for i in range(max(0,y-1)):
        print("-1",end = " ")
    if y >= 1:
        print("-1")
    else:
        print()


