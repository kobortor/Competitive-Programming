N = int(input())

c = 1

for n in range(1, N + 2):
    c = c * 2 * (2*n-1) // (n + 1)

print(c)
