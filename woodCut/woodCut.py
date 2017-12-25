# determine the optimal way
# to slice a board of wood (length N)
# into sub pieces

# optimal means yielding the greatest profit
# i.e., given N, p1, p2, ..., pn, find the greatest
# greatest combination <pi, pj, pk,...> such that
# i + j + k ... = N and the sum of the members of
# the combination are as large as possible

'''
OBSERVATION: 

the problem never asks where the cuts should be placed
nor does it ask for the lengths of the substituent pieces
after the cuts; therefore, we need not check the combinations 
of cuts: THIS IS WHAT MAKES IT A DP SOLUTION

The fact that we can precalculate best[k] for 1 <= k <= N
helps us avoid recursively generating all the possible combinations
and testing them against the maximum
'''

# The code that generates the list of cuts is commented out

N = int(input()); p = [0] + list(map(int, input().split())); b = [0] # ;choice = [0 for i in range(N + 1)]
for i in range(1, N + 1): # determine b[i] for i in 1..N
	currentMax = 0; j = 0
	while(j <= i - j):
		if b[j] + p[i - j] > currentMax: # lol b[j]
			currentMax = b[j] + p[i - j]
			# choice[i] = i - j
		j+=1
	b.append(currentMax)
print(b[N]) # print(b)

# cut = []
# k = N
# while k > 0: 
# 	cut.append(choice[k], )
# 	k -= choice[k]
# print(cut)