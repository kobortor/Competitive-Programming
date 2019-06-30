L = input()
N = str(input())

non_zeros = []
for i in range(1, L):
    if N[i] != "0":
        non_zeros.append(2 * i - L)

non_zeros.sort(cmp=lambda x,y : abs(x) - abs(y))

best = -1

for i in range(min(2, len(non_zeros))):
    idx = (non_zeros[i] + L) / 2
    lft = N[0 : idx]
    rht = N[idx :]

    if best == -1:
        best = int(lft) + int(rht)
    else:
        best = min(best, int(lft) + int(rht))

print best
