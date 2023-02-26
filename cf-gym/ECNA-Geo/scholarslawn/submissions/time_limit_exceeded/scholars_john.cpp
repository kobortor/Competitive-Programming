#include <iostream>
#include <cmath>
using namespace std;

const int MAXLINES = 500;
const double INF = 1.0e20;
const double TOL = 1.0e-6;

bool equals(double a, double b)
{
    return (fabs(a-b) < TOL);
}
class point
{
public:
    double x, y;
    double dist;        // used for Dijkstra's
    bool known;
    int adj[MAXLINES];
    int nadj=0;

    point(double xx=0.0, double yy=0.0) : x(xx), y(yy)
    {
        dist = INF;
        known = false;
        adj[0] = -1;
        nadj = 0;
    }
};

point *points[MAXLINES*MAXLINES];        // probably more than enough
int npoints = 0;

void addEdge(int,int);

int findPoint(double x, double y)
{
    for(int i=0; i<npoints; i++) {
        if (equals(points[i]->x, x) && equals(points[i]->y, y))
            return i;
    }
    points[npoints] = new point(x, y);
    return npoints++;
}

int findStudentPoint(double x, double y)
{
    int save = npoints;
    int ip = findPoint(x, y);
    if (npoints == save)
        return ip;
                        // case where student not at intersection
                        //   need to determine which two points it lies between
    for(int i=0; i<npoints-1; i++) {
        for(int j=0; j<points[i]->nadj; j++) {
            int k = points[i]->adj[j];
            if (k < i)          // check if we've used this segment already
                continue;
            double dx1 = points[i]->x - points[k]->x;
            double dy1 = points[i]->y - points[k]->y;
            double dx2 = points[i]->x - x;
            double dy2 = points[i]->y - y;
            if (!equals(dx1*dy2, dx2*dy1))
                continue;
            double minx = points[i]->x;
            double maxx = points[k]->x;
            if (maxx < minx) {
                double tmp = minx;
                minx = maxx;
                maxx = tmp;
            }
            if ((!equals(x, minx) && (x < minx)) || (!equals(x, maxx) && (x > maxx)))
                continue;
            double miny = points[i]->y;
            double maxy = points[k]->y;
            if (maxy < miny) {
                double tmp = miny;
                miny = maxy;
                maxy = tmp;
            }
            if ((!equals(y, miny) && (y < miny)) || (!equals(y, maxy) && (y > maxy)))
                continue;
            addEdge(ip, i);
            addEdge(ip, k);
            return ip;
        }
    }
    cout << "ERROR: student position not on any path";
    exit(-1);
}

class line
{
public:
    struct {
        int pindex;
        double t;
    } p[MAXLINES];
    int npoints;

    line(double px1, double py1, double px2, double py2)
    {
        p[0].pindex = findPoint(px1, py1);
        p[0].t = 0.0;
        p[1].pindex = findPoint(px2, py2);
        p[1].t = 1.0;
        npoints = 2;
    }

    void insertPoint(int index, double t)
    {
        for(int i=0; i<npoints; i++)
            if (p[i].pindex == index)
                return;
        int i = npoints;
        while (i > 0 && p[i-1].t > t) {
            p[i] = p[i-1];
            i--;
        }
        p[i].pindex = index;
        p[i].t = t;
        npoints++;
    }

    void printLine()
    {
        for(int i=0; i<npoints; i++) {
            cout << '(' << points[p[i].pindex]->x << ',' << points[p[i].pindex]->y << ' ' << p[i].t << ')';
        }
        cout << endl;
    }
};

line *lines[MAXLINES];

double calcDist(double x1, double y1, double x2, double y2)
{
    double dx = x1-x2;
    double dy = y1-y2;
    return sqrt(dx*dx + dy*dy);
}

bool getTU(point *pa, point *pb, point *pc, point *pd, double&t, double&u)
{
    double a = pb->x - pa->x;
    double b = pd->x - pc->x;
    double d = pb->y - pa->y;
    double e = pd->y - pc->y;
    double den = b*d - a*e;
    if (den == 0.0)         // check for parallel lines
        return false;
    double c = pc->x - pa->x;
    double f = pc->y - pa->y;
//cout << a << ',' << b << ',' << c << ',' << d << ',' << e << ',' << f << endl;
                                // solve at - cu = c
                                //       dt - eu = f
    t = (b*f - c*e)/den;
    u = (a*f - c*d)/den;
    return true;
}

void processIntersection(int l1, int l2)
{
    point *pa = points[lines[l1]->p[0].pindex];
    point *pb = points[lines[l1]->p[lines[l1]->npoints-1].pindex];
    point *pc = points[lines[l2]->p[0].pindex];
    point *pd = points[lines[l2]->p[lines[l2]->npoints-1].pindex];
    double t, u;
//cout << '(' << pa->x << ',' << pa->y << ")-(" << pb->x << ',' << pb->y << ')' << endl;
//cout << '(' << pc->x << ',' << pc->y << ")-(" << pd->x << ',' << pd->y << ')' << endl;
    if (!getTU(pa, pb, pc, pd, t, u))         // check for parallel lines
        return;                         //   in this problem can ignore them
//    cout << t << ' ' << u << endl;
    if (t < 0.0 || t > 1.0  || u < 0.0 || u > 1.0)  // no intersection
        return;
    double a = pb->x - pa->x;
    double d = pb->y - pa->y;
//    int pindex = findPoint(pa->x + t*a, pa->y + t*d);   // add point to graph points
    points[npoints] = new point(pa->x + t*a, pa->y + t*d);
    int pindex = npoints++;
    lines[l1]->insertPoint(pindex, t);
    lines[l2]->insertPoint(pindex, u);
}

void addEdge(int i1, int i2)
{
    int nadj1 = points[i1]->nadj++;
    int nadj2 = points[i2]->nadj++;
    points[i1]->adj[nadj1] = i2;
    points[i2]->adj[nadj2] = i1;
}

int findClosestUnvisited()
{
    double minD = INF;
    int ans = -1;
    for(int i=0; i<npoints; i++) {
        if (points[i]->known)
            continue;
        if (points[i]->dist < minD) {
            minD = points[i]->dist;
            ans = i;
        }
    }
    return ans;
}

void dijkstras(int source)
{
    points[source]->dist = 0.0;
    int v;
    while ((v = findClosestUnvisited()) != -1) {
        points[v]->known = true;
        double x = points[v]->x;
        double y = points[v]->y;
        for(int i=0; i<points[v]->nadj; i++) {
            int w = points[v]->adj[i];
            if (points[w]->known)
                continue;
            double d = calcDist(x, y, points[w]->x, points[w]->y);
            if (points[v]->dist + d < points[w]->dist)
                points[w]->dist = points[v]->dist + d;
        }
    }

}
int main()
{
    int length, width;
    int nlines;
    cin >> nlines;
    for(int i=0; i<nlines; i++) {
        int xa, ya, xb, yb;
        cin >> xa >> ya >> xb >> yb;
        lines[i] = new line(xa, ya, xb, yb);
        for(int j=0; j<i; j++)
            processIntersection(i, j);
    }
/*
    for(int i=0; i<nlines; i++) {
        lines[i]->printLine();
    }
/**/
                                // build graph
    for(int i=0; i<nlines; i++) {
        for(int j=1; j<lines[i]->npoints; j++)
            addEdge(lines[i]->p[j-1].pindex, lines[i]->p[j].pindex);
    }
                                // read in student info an calculate shortest distances
                                //   to each graph point
    double sx, sy, sv;
    cin >> sx >> sy >> sv;
    int is = findStudentPoint(sx, sy);
    dijkstras(is);
/*
    for(int i=0; i<npoints; i++) {
        cout << '(' << points[i]->x << ',' << points[i]->y << ") dist = " << points[i]->dist << endl;
    }
/**/
                                // read in fellow info and solve problem
    double fx1, fy1, fx2, fy2;
    double fv;
    cin >> fx1 >> fy1 >> fx2 >> fy2 >> fv;
    point *fp1 = new point(fx1, fy1), *fp2 = new point(fx2, fy2);
    double earliest = INF;
    for(int i=0; i<npoints-1; i++) {
        for(int j=0; j<points[i]->nadj; j++) {
            int k = points[i]->adj[j];
            if (k < i)          // check if we've used this segment already
                continue;
            double t,u;
//cout << "check segment " << points[i]->x << ',' << points[i]->y << '-' << points[k]->x << ',' << points[k]->y << endl;
            if (!getTU(points[i], points[k], fp1, fp2, t, u))
                continue;
            if (t < 0.0 || t > 1.0 || u < 0.0 || u > 1.0)
                continue;
            double xint = points[i]->x + t*(points[k]->x - points[i]->x);
            double yint = points[i]->y + t*(points[k]->y - points[i]->y);
//cout << "Intersection point: (" << xint << ',' << yint << ")" << endl;
            double fTime = calcDist(fx1, fy1, xint, yint)/fv;
//cout << "   fellow time = " << fTime << endl;
            double sDist1 = points[i]->dist + calcDist(points[i]->x, points[i]->y, xint, yint);
            double sDist2 = points[k]->dist + calcDist(points[k]->x, points[k]->y, xint, yint);
            if (sDist2 < sDist1)
                sDist1 = sDist2;
            double sTime = sDist1/sv;
//cout << "  student time = " << sTime <<  " diff = " << sTime-fTime << endl;
            if ((sTime < fTime || equals(sTime, fTime)) && fTime < earliest)
                earliest = fTime;
        }
    }
    if (earliest == INF)
        cout << "Impossible" << endl;
    else
       printf("%.8f\n", earliest);
}
