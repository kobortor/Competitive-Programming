import math
import sys
n, m = map(int, input().split())

if n > 100:
  print("impossible")
  sys.exit(0)

cachen = [-1 for i in range(10000)]
cachem = [-1 for i in range(10000)]

def fpow_help(b, p):
  if p == 0:
    return 1
  ret = fpow_help(b, p // 2)
  if p % 2 == 1:
    return ret * ret * b
  return ret * ret

def fpow(b, p):
  if p == n:
    if cachen[b] == -1:
      cachen[b] = fpow_help(b, p)
    return cachen[b]
  if p == n - 1:
    if cachem[b] == -1:
      cachem[b] = fpow_help(b, p)
    return cachem[b]

q = 2
while fpow(q, n - 1) < 1e19: # Just in case
  # print(q)
  best_p = -1
  for p in range(q-1, 0, -1):
    top1 = m * p * fpow(q, n)
    bot1 = q * (fpow(q, n) - fpow(q-p, n))
    
    if top1 < bot1:
      break

    top2 = m*p*fpow(q - p, n - 1)
    bot2 = (fpow(q, n) - fpow(q-p, n))

    if top2 < bot2:
      break

    good1 = (top1 % bot1 == 0)

    if not good1:
      continue

    good2 = (top2 % bot2 == 0)
    # good2 = True

    if good1 and good2:
      best_p = p
      # print(p, q)
      # sys.exit(0)

  if best_p != -1:
    print(best_p, q)
    sys.exit(0)

  q += 1

print("impossible")