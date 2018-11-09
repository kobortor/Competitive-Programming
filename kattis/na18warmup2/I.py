N, S = input().split()
N = int(N)
S = int(S)

arr = []
for i in range(N):
    a, b = input().split()
    arr.append([int(b), a])

arr.sort()
arr.reverse()

out = []

for i in range(N):
    if arr[i][0] <= S:
        S -= arr[i][0]
        out.append(arr[i][1])

if S == 0:
    print(len(out))
    for ss in out:
        print(ss)
else:
    print(0)


