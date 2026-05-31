t = int(input())
while (t!=0):
	t -= 1
	n = int(input())
	a = list(map(int,input().split()))
	b = [i for i in a]
	k = 0
	visited = [False]*n
	for i in range(1,n):
		if a[i] < a[i-1]:
			k = max(a[i-1]-a[i],k)
			a[i] += k
	for i in range(1,n):
		if b[i] < b[i-1] and b[i] + k < b[i-1]:
			break
		if b[i] < b[i-1]:	
			b[i] += k
	else:
		print("YES")
		continue
	print("NO") 
