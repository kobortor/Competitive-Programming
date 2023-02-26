#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double EPS = 1e-9;

bool
    DEBUG = false,
    DEBUG_LIST = false,
    DEBUG_SELECT = false;

struct Point {
    double
        x, y;
};

struct Segment {
    Point
        p1, p2;
};

const uint32_t
    MAX_SEGMENTS = 501;

double
  sDist = 1e100;

//============================================================================
//========================= point code =======================================
//============================================================================

Point operator+(Point a,Point b) {
    return Point{a.x+b.x, a.y+b.y};
}

Point operator-(Point a,Point b) {
    return Point{a.x-b.x, a.y-b.y};
}

Point operator*(Point a,double b) {
    return Point{a.x*b, a.y*b};
}

double operator*(Point a,Point b) {
    return a.x * b.y - a.y * b.x;
}

bool operator==(Point a,Point b) {
    return a.x == b.x && a.y == b.y;
}

bool operator!=(Point a,Point b) {
    return a.x != b.x || a.y != b.y;
}

double dist(Point p1, Point p2) {
    double
        x1 = p1.x,
        x2 = p2.x,
        y1 = p1.y,
        y2 = p2.y;

    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

bool pointInSegment(Point p,Segment s) {
    double
        x1, x2, y1, y2;

    x1 = x2 = s.p1.x;
    if (s.p2.x < x1)
        x1 = s.p2.x;
    if (s.p2.x > x2)
        x2 = s.p2.x;

    y1 = y2 = s.p1.y;
    if (s.p2.y < y1)
        y1 = s.p2.y;
    if (s.p2.y > y2)
        y2 = s.p2.y;

    if (p.x < x1 || p.x > x2 || p.y < y1 || p.y > y2)
        return false;

    double d = fabs((s.p2.x-s.p1.x)*(s.p1.y-p.y)-(s.p1.x-p.x)*(s.p2.y-s.p1.y))
    	 / sqrt((s.p2.x-s.p1.x)*(s.p2.x-s.p1.x)+(s.p2.y-s.p1.y)*(s.p2.y-s.p1.y));
    if (d < sDist)
      sDist = d;

    return fabs((p.x - s.p1.x) * (s.p2.y - s.p1.y) - (p.y - s.p1.y) * (s.p2.x - s.p1.x)) <= EPS;
}

bool intersect(Segment s1,Segment s2,Point &ip) {
    Point
        p = s1.p1,
        q = s2.p1,
        r = s1.p2 - p,
        s = s2.p2 - q,
        v = q - p;
    double
        t, u,
        d;

    if (s1.p1 == s2.p1 || s1.p1 == s2.p2) {
        ip = s1.p1;
        return true;
    }

    if (s1.p2 == s2.p1 || s1.p1 == s2.p2) {
        ip = s1.p2;
        return true;
    }

    d = r * s;

    if (d == 0)
        return false;

    t = (v * s) / d;
    u = (v * r) / d;

    if ((t >= 0) && t <= 1 && u >= 0 && u <= 1) {
        ip = p + r * t;
        return true;
    }

    return false;
}

int
    *heap;

int32_t
    nHeap = 0;

Point
    *pList;
double
    *times;
bool
    *inHeap,
    *reached;
int32_t
    *hPos,
    *nIntersect;

void hInsert(int32_t val) {
    int32_t
        pos,
        parent,
        tmp;

    if (DEBUG)
        cout << "hInsert(" << val << ')' << endl;

    heap[nHeap] = val;
    pos = hPos[val] = nHeap;
    nHeap++;

    while (pos != 0) {
        parent = (pos - 1) / 2;
        if (times[heap[parent]] <= times[heap[pos]])
            break;
        tmp = heap[parent];
        heap[parent] = heap[pos];
        heap[pos] = tmp;
        hPos[heap[parent]] = parent;
        hPos[heap[pos]] = pos;
        pos = parent;
    }
}

void hRemoveMin() {
    int32_t
        c,
        pos,
        tmp;

    if (DEBUG)
        cout << "hRemoveMin()" << endl;

    nHeap--;

    heap[0] = heap[nHeap];
    hPos[heap[0]] = 0;

    pos = 0;

    while (pos < nHeap / 2) {
        c = 2 * pos + 1;
        if (c < nHeap - 1 && times[heap[c+1]] < times[heap[c]])
            c++;
        if (times[heap[pos]] <= times[heap[c]])
            break;
        tmp = heap[pos];
        heap[pos] = heap[c];
        heap[c] = tmp;
        hPos[heap[pos]] = pos;
        hPos[heap[c]] = c;
        pos = c;
    }
}

/*
void hRemove(int32_t val) {
    int
        c,
        pos,
        tmp;

    if (DEBUG)
        cout << "hRemove(" << val << ')' << endl;

    nHeap--;

    pos = hPos[val];

    heap[pos] = heap[nHeap];
    hPos[heap[pos]] = pos;

    while (pos < nHeap / 2) {
        c = 2 * pos + 1;
        if (c < nHeap - 1 && times[heap[c+1]] < times[heap[c]])
            c++;
        if (times[heap[pos]] <= times[heap[c]])
            break;
        tmp = heap[pos];
        heap[pos] = heap[c];
        heap[c] = tmp;
        hPos[heap[pos]] = pos;
        hPos[heap[c]] = c;
        pos = c;
    }
}
*/

void hReplace(int32_t val) {
    int
        parent,
        pos,
        tmp;

    if (DEBUG)
        cout << "hReplace(" << val << ')' << endl;

    pos = hPos[val];

    while (pos != 0) {
        parent = (pos - 1) / 2;
        if (times[heap[parent]] <= times[heap[pos]])
            break;
        tmp = heap[parent];
        heap[parent] = heap[pos];
        heap[pos] = tmp;
        hPos[heap[parent]] = parent;
        hPos[heap[pos]] = pos;
        pos = parent;
    }
}

int main() {
    Point
        p{},
        pScholar{};
    int32_t
        cur=-1,
        nSegs=0,
        s1, s2,
        *iSegList;
    double
        vScholar,
        vFellow,
        curTime,
        t,
        tFellow,
        bestFellow;
    Segment
        fellowSeg{},
        *segList;

    //
    // memory allocation
    //

    segList = new Segment[MAX_SEGMENTS+1];
    pList = new Point[MAX_SEGMENTS*MAX_SEGMENTS+MAX_SEGMENTS];
    times = new double[MAX_SEGMENTS*MAX_SEGMENTS+MAX_SEGMENTS];
    inHeap = new bool[MAX_SEGMENTS*MAX_SEGMENTS+MAX_SEGMENTS];
    reached = new bool[MAX_SEGMENTS*MAX_SEGMENTS+MAX_SEGMENTS];
    nIntersect = new int32_t[MAX_SEGMENTS+1];
    iSegList = new int32_t[MAX_SEGMENTS*MAX_SEGMENTS+MAX_SEGMENTS];
    heap = new int32_t[MAX_SEGMENTS*MAX_SEGMENTS+MAX_SEGMENTS];
    hPos = new int32_t[MAX_SEGMENTS*MAX_SEGMENTS+MAX_SEGMENTS];

    //
    // input
    //

    cin >> nSegs;

    for (int i=0;i<nSegs;i++)
        cin >> segList[i].p1.x >> segList[i].p1.y >> segList[i].p2.x >> segList[i].p2.y;

    cin >> pScholar.x >> pScholar.y >> vScholar;

    cin >> fellowSeg.p1.x >> fellowSeg.p1.y >> fellowSeg.p2.x >> fellowSeg.p2.y >> vFellow;

    segList[nSegs] = fellowSeg;

    if (DEBUG) {
        cout << "After input:" << endl;
        cout << "nSegments: " << nSegs << endl;
        if (DEBUG_LIST) {
            for (int i = 0; i < nSegs; i++)
                cout << i << '\t' << segList[i].p1.x << ',' << segList[i].p1.y << '\t'
                    << segList[i].p2.x << ',' << segList[i].p2.y << endl;
            cout << endl;
        }
        cout << "Scholar start: " << pScholar.x << ',' << pScholar.y << endl;
        cout << "\n===================================\n" << endl;
    }

    //
    // generate list of intersection points
    //

    for (s1=0;s1<nSegs;s1++)
        for (s2=s1+1;s2<=nSegs;s2++)
            if (intersect(segList[s1],segList[s2],p)) {
                pList[s1 * (nSegs + 1) + s2] = p;
                iSegList[s1 * (nSegs + 1) + nIntersect[s1]] = s2;
                nIntersect[s1]++;

                if (s2 < nSegs) {
                    pList[s2 * (nSegs + 1) + s1] = p;
                    iSegList[s2 * (nSegs + 1) + nIntersect[s2]] = s1;
                    nIntersect[s2]++;
                }
            }

    if (DEBUG_LIST) {
        for (s1=0;s1<nSegs;s1++)
            for (s2=0;s2<nIntersect[s1];s2++) {
                int tmp = s1 * (nSegs+1) + s2;
                cout << "Point: " << tmp << ' ' << s1 << ' ' << iSegList[tmp] << ' '
                     << pList[s1*(nSegs+1)+iSegList[tmp]].x << ','
                     << pList[s1*(nSegs+1)+iSegList[tmp]].y << ' '
                     << times[s1*(nSegs+1)+iSegList[tmp]] << endl;
            }
    }

    //
    // now, find which segments have the scholar's start position, add them to heap
    //

    for (s1=0;s1<nSegs;s1++)
        if (pointInSegment(pScholar,segList[s1])) {
            // go through all intersection points, add to heap
            for (int j=0;j<nIntersect[s1];j++) {
                s2 = iSegList[s1*(nSegs+1)+j];
                int
                    tmpS1 = s1,
                    tmpS2 = s2;
                if (s1 > s2) {
                    tmpS1 = s2;
                    tmpS2 = s1;
                }
                times[tmpS1*(nSegs+1)+tmpS2] =
                        dist(pList[tmpS1*(nSegs+1)+tmpS2],pScholar) / vScholar;
                inHeap[tmpS1*(nSegs+1)+tmpS2] = true;
                hInsert(tmpS1*(nSegs+1)+tmpS2);
            }
            cur = s1;
        }
    if (cur == -1) {
        cerr << "Error: Cannot find scholar start point" << endl;
        cerr << "sDist = " << sDist << endl;
        cout << "Impossible" << endl;
        return 0;
    }

    //
    // now, continue until all paths reached
    //

    int nIt = 0;
    while (nHeap > 0) {
        nIt++;
        if (DEBUG)
            //if (nIt % 1024 == 0)
                cout << nIt << endl;
        //
        // select best segment
        //

        cur = heap[0];
        curTime = times[heap[0]];

        if (DEBUG_SELECT)
            cout << "Selected " << cur << '(' << (cur/(nSegs+1)) << ',' << (cur%(nSegs+1))
                << ") at time " << curTime << ' ' << pList[cur].x << ',' << pList[cur].y << endl;

        hRemoveMin();

        reached[cur] = true;

        //
        // update
        //

        s1 = cur / (nSegs + 1);
        for (int i=0;i<nIntersect[s1];i++) {
            s2 = iSegList[s1*(nSegs+1)+i];
            int
                tmpS1 = s1,
                tmpS2 = s2;
            if (s1 > s2) {
                tmpS1 = s2;
                tmpS2 = s1;
            }
            if (reached[tmpS1*(nSegs+1)+tmpS2])
                continue;
            t = curTime + dist(pList[tmpS1*(nSegs+1)+tmpS2],pList[cur]) / vScholar;
            if (inHeap[tmpS1*(nSegs+1)+tmpS2]) {
                if (t < times[tmpS1 * (nSegs + 1) + tmpS2]) {
                    times[tmpS1 * (nSegs + 1) + tmpS2] = t;
                    hReplace(tmpS1 * (nSegs + 1) + tmpS2);
//                    hRemove(tmpS1 * (nSegs + 1) + tmpS2);
//                    hInsert(tmpS1 * (nSegs + 1) + tmpS2);
                }
            } else {
                times[tmpS1 * (nSegs + 1) + tmpS2] = t;
                hInsert(tmpS1 * (nSegs + 1) + tmpS2);
                inHeap[tmpS1 * (nSegs + 1) + tmpS2] = true;
            }
        }

        s1 = cur % (nSegs + 1);
        for (int i=0;i<nIntersect[s1];i++) {
            s2 = iSegList[s1*(nSegs+1)+i];
            int
                    tmpS1 = s1,
                    tmpS2 = s2;
            if (s1 > s2) {
                tmpS1 = s2;
                tmpS2 = s1;
            }
            if (reached[tmpS1*(nSegs+1)+tmpS2])
                continue;
            t = curTime + dist(pList[tmpS1*(nSegs+1)+tmpS2],pList[cur]) / vScholar;
            if (inHeap[tmpS1*(nSegs+1)+tmpS2]) {
                if (t < times[tmpS1 * (nSegs + 1) + tmpS2]) {
                    times[tmpS1 * (nSegs + 1) + tmpS2] = t;
                    hReplace(tmpS1 * (nSegs + 1) + tmpS2);
//                    hRemove(tmpS1 * (nSegs + 1) + tmpS2);
//                    hInsert(tmpS1 * (nSegs + 1) + tmpS2);
                }
            } else {
                times[tmpS1 * (nSegs + 1) + tmpS2] = t;
                hInsert(tmpS1 * (nSegs + 1) + tmpS2);
                inHeap[tmpS1 * (nSegs + 1) + tmpS2] = true;
            }
        }
    }

    //
    // now, check all intersections with fellow's path and see if any of them works
    //

    bestFellow = 1e100;

    for (int i=0;i<nSegs;i++) {
        if (iSegList[i * (nSegs + 1) + nIntersect[i] - 1] == nSegs) {
            t = times[i * (nSegs + 1) + nSegs];
            tFellow = dist(fellowSeg.p1, pList[i * (nSegs + 1) + nSegs]) / vFellow;
            if (DEBUG_LIST) {
                cout << "point " << i << "   " << pList[i*(nSegs+1)+nSegs].x <<
                        ',' << pList[i*(nSegs+1)+nSegs].y << endl;
                cout << "t = " << t << "   tFellow = " << tFellow << endl;
            }

            if (t <= tFellow + EPS && tFellow < bestFellow)
                bestFellow = tFellow;

            if (DEBUG && fabs(t-tFellow) < 1e-6)
                cout << "Close values: t = " << setprecision(16) << t << "  tFellow = "
                    << tFellow << endl;
        }
    }

    if (DEBUG_LIST) {
        for (s1=0;s1<nSegs;s1++)
            for (s2=0;s2<nIntersect[s1];s2++) {
                int tmp = s1 * (nSegs+1) + s2;
                cout << "Point: " << tmp << ' ' << s1 << ' ' << iSegList[tmp] << ' '
                    << pList[s1*(nSegs+1)+iSegList[tmp]].x << ','
                    << pList[s1*(nSegs+1)+iSegList[tmp]].y << ' '
                    << times[s1*(nSegs+1)+iSegList[tmp]] << endl;
            }
    }

    if (bestFellow > 1e99)
        cout << "Impossible" << endl;
    else
        cout << setprecision(10) << bestFellow << endl;

    //
    // deallocation
    //

    delete[] segList;
    delete[] pList;
    delete[] times;
    delete[] inHeap;
    delete[] reached;
    delete[] nIntersect;
    delete[] iSegList;
    delete[] heap;
    delete[] hPos;

    return 0;
}
