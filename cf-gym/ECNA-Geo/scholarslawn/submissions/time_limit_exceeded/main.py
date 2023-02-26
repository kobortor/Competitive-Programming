#!/usr/bin/python3

from fractions import Fraction
from math import sqrt

debug = False


def pointInLine(pt, li):
    if (pt[0] == li[0] and pt[1] == li[1]) or (pt[0] == li[2] and pt[1] == li[3]):
        return False

    xx1 = min(li[0], li[2])
    xx2 = max(li[0], li[2])
    yy1 = min(li[1], li[3])
    yy2 = max(li[1], li[3])

    if pt[0] < xx1 or pt[0] > xx2 or pt[1] < yy1 or pt[1] > yy2:
        return False

    return (pt[0] - li[0]) * (li[3] - li[1]) - (pt[1] - li[1]) * (li[2] - li[0]) == 0


def splitAtPoints():
    for pt in points:
        j = 0
        while j < len(lines):
            if pointInLine(pt, lines[j]):
                # print('split ', lines[j], pt)
                lines.append([pt[0], pt[1], lines[j][2], lines[j][3], lines[j][4]])
                lines[j][2] = pt[0]
                lines[j][3] = pt[1]
            j += 1


def intersect(line1, line2):
    px = line1[0]
    py = line1[1]
    rx = line1[2] - px
    ry = line1[3] - py

    qx = line2[0]
    qy = line2[1]
    sx = line2[2] - qx
    sy = line2[3] - qy

    vx = qx - px
    vy = qy - py

    d = rx * sy - ry * sx

    if d == 0:
        return None

    tn = vx * sy - vy * sx
    un = vx * ry - vy * rx

    t = tn / d
    u = un / d

    if 0 < t < 1 and 0 < u < 1:
        return px + t * rx, py + t * ry


def dist(p1, p2):
    dx = points[p1][0] - points[p2][0]
    dy = points[p1][1] - points[p2][1]

    return sqrt(dx * dx + dy * dy)


def dijkstra(v0, t, lim):
    for j in range(len(pInfo)):
        pInfo[j][0] = False

    if debug:
        print('v0:', v0)
        print('t:', t)
        print('lim:', lim)

    pInfo[v0][0] = True
    pInfo[v0][lim + 2] = 0

    for w in pInfo[v0][1]:
        if w[1] == lim:
            pInfo[w[0]][lim + 2] = dist(v0, w[0]) / t

    for j in range(len(pInfo) - 2):
        best = None
        bestI = None
        for k in range(len(pInfo)):
            if not pInfo[k][0] and pInfo[k][lim + 2] is not None:
                if best is None or pInfo[k][lim + 2] < best:
                    best = pInfo[k][lim + 2]
                    bestI = k

        if bestI is None:
            break

        pInfo[bestI][0] = True

        for w in pInfo[bestI][1]:
            if w[1] == lim:
                if (pInfo[w[0]][lim + 2] is None) or best + dist(bestI, w[0]) / t < pInfo[w[0]][lim + 2]:
                    pInfo[w[0]][lim + 2] = best + dist(bestI, w[0]) / t


n = int(input())

lines = []
points = []

for i in range(n):
    (x1, y1, x2, y2) = map(Fraction, input().split(' '))
    # x1 = Fraction(x1)
    # y1 = Fraction(y1)
    # x2 = Fraction(x2)
    # y2 = Fraction(y2)
    lines.append([x1, y1, x2, y2, 0])
    p = (x1, y1)
    if p not in points:
        points.append(p)
    q = (x2, y2)
    if q not in points:
        points.append(q)

(xs, ys, vs) = map(Fraction, input().split(' '))
p = (xs, ys)
if p not in points:
    points.append(p)

(x1f, y1f, x2f, y2f, vf) = map(Fraction, input().split(' '))
p = (x1f, y1f)
if p not in points:
    points.append(p)
q = (x2f, y2f)
if q not in points:
    points.append(q)

lines.append([x1f, y1f, x2f, y2f, 1])

# find intersection points
for i1 in range(len(lines)):
    for i2 in range(i1 + 1, len(lines)):
        ip = intersect(lines[i1], lines[i2])
        if ip is not None:
            points.append(ip)

# split lines at points if necessary
splitAtPoints()

# for p in points:
# print(p)
# for line in lines:
# print(line)
# print(lines[0][2].numerator, len(lines))

pInfo = []
for p in points:
    pInfo.append([False, [], None, None])

for line in lines:
    for i1 in range(len(points)):
        if line[0] == points[i1][0] and line[1] == points[i1][1]:
            for i2 in range(len(points)):
                if line[2] == points[i2][0] and line[3] == points[i2][1]:
                    pInfo[i1][1].append((i2, line[4]))
                    pInfo[i2][1].append((i1, line[4]))

for i1 in range(len(points)):
    if points[i1][0] == xs and points[i1][1] == ys:
        dijkstra(i1, vs, 0)
    if points[i1][0] == x1f and points[i1][1] == y1f:
        dijkstra(i1, vf, 1)

if debug:
    print('pInfo:', pInfo)

earliest = None
for pi in pInfo:
    if pi[2] is not None and pi[3] is not None and pi[2] <= pi[3]:
        if earliest is None:
            earliest = pi[3]
        elif pi[3] < earliest:
            earliest = pi[3]

if earliest is None:
    print('Impossible')
else:
    print(earliest)

if debug:
    for i in range(len(pInfo)):
        print('i, points[i], pInfo[i]:', i, points[i], pInfo[i])
