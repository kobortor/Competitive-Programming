# verify the geometry and a few other tricky things (e.g., # of decimal
# points in floats). Syntax, data bounds, white space, etc. handled by
# other validators

import sys
import re
epsilon = 1e-9

def triple(w1,w2,s):
  return w1[0]*w2[1]+w1[1]*s[0]+w2[0]*s[1]-s[0]*w2[1]-s[1]*w1[0]-w2[0]*w1[1]

def btwn(a,b,c):
  mx = min(a[0],b[0])
  MX = max(a[0],b[0])
  my = min(a[1],b[1])
  MY = max(a[1],b[1])
  if c[0] >= mx-epsilon and c[0] <= MX+epsilon and\
     c[1] >= my-epsilon and c[1] <= MY+epsilon:
       return True
  else:
     return False

# floating point numbers can have at most 4 decimal places; if there is a
# decimal point then there has to be a leading zero. (No scientific
# notation here; also disallows things like "09", but allows "-0".)

fl = re.compile(r"^[-+]?(0|([1-9]([0-9]*)))([.][0-9]{,4})?$")
retcode = 42

n = int(sys.stdin.readline())

# read in the n walkway coordinates (no validation performed here):
w1 = [[0,0] for i in range(n)]
w2 = [[0,0] for i in range(n)]
for i in range(n):
  temp = list(map(int,sys.stdin.readline().split()))
  w1[i] = temp[0:2]
  w2[i] = temp[2:4]

# read in student coordinates and velocity (check float format):
[ss,se,sv] = sys.stdin.readline().split()
if re.match(fl,ss) == None:
  print("Bad student start x on next-to-last line: "+ss)
  retcode = 43
if re.match(fl,se) == None:
  print("Bad student start y on next-to-last line: "+se)
  retcode = 43
if re.match(fl,sv) == None:
  print("Bad student velocity on next-to-last line: "+sv)
  retcode = 43
ss = float(ss)
se = float(se)
sv = float(sv)

# read in fellow's path and velocity (check float format):
temp = sys.stdin.readline().split()
for i in range(len(temp)):
  if re.match(fl,temp[i]) == None:
    print("Bad float value on last line: "+temp[i])
    retcode = 43
temp = list(map(float,temp))
f1 = temp[0:2]
f2 = temp[2:4]
fv = temp[4]

# Make sure student position lies along a path:
# triple product of endpoints and student == 0; student values between endpoints
onpath = False
for i in range(n):
  t = triple(w1[i],w2[i],[ss,se])
  if abs(t) < epsilon:
    if btwn(w1[i],w2[i],[ss,se]):
      onpath = True

if not onpath:
  print("Student position does not lie on a path")
  retcode = 43

# Make sure no collinear paths intersect
w1.append(f1) # add fellow's path to list of walkways
w2.append(f2)

for i in range(n):
  for j in range(i+1,n+1):
    if abs(triple(w1[i],w2[i],w1[j]))<epsilon and abs(triple(w1[i],w2[i],w2[j]))<epsilon:
      if btwn(w1[i],w2[i],w1[j]) or btwn(w1[i],w2[i],w2[j]) or\
         btwn(w1[j],w2[j],w1[i]) or btwn(w1[j],w2[j],w2[i]):
        print("Paths "+str(i)+" and "+str(j)+" overlap")
        retcode = 43

exit(retcode)
