import itertools

n = 10

solns = []

for unordered_center in itertools.combinations(range(1, n + 1), n // 2):
    for center in itertools.permutations(list(unordered_center)):
        for start in range(1, n + 1):
            tot = start + center[0] + center[1]
            outside = []
            for i in range(n // 2):
                outside.append(tot - center[i] - center[i + 1 - n // 2])

            inside = list(center)

            soln = []
            idx = outside.index(min(outside))
            for i in range(n // 2):
                soln.append(outside[idx + i - n // 2])
                soln.append(inside[idx + i - n // 2])
                soln.append(inside[idx + i + 1 - n // 2])

            # print(sorted(list(everything)))

            if sorted(list(set(inside + outside))) == list(range(1, n + 1)):
                solns.append("".join(str(x) for x in soln))

solns = [int(x) for x in solns if len(x) == 16]
print(max(solns))
