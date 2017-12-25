# calculate number of ways to
# walk up N stairs with either
# steps of 1 or steps of 2

N = int(input())
l = []
l.append(1); l.append(2) # there is one way to walk to 1, 2 ways to walk to 2
for i in range(2, N):
	l.append(l[i - 2] + l[i - 1])
print(l[N - 1])