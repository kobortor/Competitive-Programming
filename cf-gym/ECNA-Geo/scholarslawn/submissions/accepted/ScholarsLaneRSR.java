import java.util.*;
import java.io.*;

class Vertex {
  int i;
  double x, y;
  public HashSet<Vertex> nbr;
  public HashMap<Vertex,Double> dist;
  public int parent;
  public double bestdist;

  // Use this constructor when searching to see if a point is already in
  // the set of vertices--it assigns a -1 as the vertex id
  public Vertex(double x, double y) {
    this.x = x; this.y = y; this.i = -1;
  }

  // Use this constructor to create a brand new vertex that is not already
  // in the set of vertices; it assigns the correct vertex id which can
  // then be used to look up the "real" vertex in the v arraylist
  public Vertex(int i, double x, double y) {
    this.i = i;
    this.x = x;
    this.y = y;
    this.nbr = new HashSet<Vertex>();
    this.dist = new HashMap<Vertex,Double>();
    this.parent = -1;
    this.bestdist = Double.MAX_VALUE;
  }

  // hash vertices based on values rather than on object id
  @Override
  public int hashCode() {
    long u = Double.doubleToLongBits(x);
    long v = Double.doubleToLongBits(y);
    return (int)(u^(v>>>32));
  }

  // compare vertices based on values rather than object id;
  // also, copy over vertex id if one of the vertices is not
  // correctly labeled (just to make it easier to keep track)
  @Override
  public boolean equals(Object o) {
    Vertex other = (Vertex)o;
    if (Math.abs(other.x-this.x) < 1e-9 && Math.abs(other.y-this.y) < 1e-9) {
      if (this.i < 0 && other.i >= 0) this.i = other.i;
      else if (other.i < 0 && this.i >= 0) other.i = this.i;
      return true;
    }
    return false;
  }
}

public class ScholarsLaneRSR {
  public static int n;
  public static double[] x1,y1,x2,y2;
  public static double xs,ys,ss,xfs,yfs,xfe,yfe,sf;
  public static int sid;
  public static HashSet<Vertex> vs;
  public static ArrayList<Vertex> v;
  public static final double EPS = 1e-8;
  public static PriorityQueue<Vertex> pq;
  public static boolean visited[];

  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    n = Integer.parseInt(in.readLine());
    x1 = new double[n+1];
    y1 = new double[n+1];
    x2 = new double[n+1];
    y2 = new double[n+1];
    StringTokenizer st;
    for (int i = 0; i < n; i++) {
      st = new StringTokenizer(in.readLine());
      x1[i] = Double.parseDouble(st.nextToken());
      y1[i] = Double.parseDouble(st.nextToken());
      x2[i] = Double.parseDouble(st.nextToken());
      y2[i] = Double.parseDouble(st.nextToken());
    }
    // Student position and speed:
    st = new StringTokenizer(in.readLine());
    xs = Double.parseDouble(st.nextToken());
    ys = Double.parseDouble(st.nextToken());
    ss = Double.parseDouble(st.nextToken());
    // Fellow start/end position and speed:
    st = new StringTokenizer(in.readLine());
    xfs = Double.parseDouble(st.nextToken());
    yfs = Double.parseDouble(st.nextToken());
    xfe = Double.parseDouble(st.nextToken());
    yfe = Double.parseDouble(st.nextToken());
    sf = Double.parseDouble(st.nextToken());

    // Add fellow's path:
    x1[n] = xfs; y1[n] = yfs; x2[n] = xfe; y2[n] = yfe;

    vs = new HashSet<Vertex>(); // vertices of the final graph
    v = new ArrayList<Vertex>(); // indexed version of vs
    int vn = 0; // vertex id number

    // Fellow start point is always vertex 0
    Vertex vtemp = new Vertex(vn,xfs,yfs);
    vs.add(vtemp);
    v.add(vtemp);
    vn++;
    // Student might be same as Fellow start
    vtemp = new Vertex(xs,ys);
    if (!vs.contains(vtemp)) {
      vtemp =  new Vertex(vn,xs,ys);
      vs.add(vtemp);
      v.add(vtemp);
      vn++;
    }
    sid = vtemp.i; // remember the student's vertex number, could be 0,1, or 2

    // For each path, find points of intersection with other
    // paths. Watch out for shared vertices since multiple paths
    // could meet at a common intersection.
    ArrayList<HashSet<Vertex>> interior = new ArrayList<HashSet<Vertex>>();
    ArrayList<HashMap<Vertex,Double>> len = new ArrayList<HashMap<Vertex,Double>>();
    for (int i=0; i <= n; i++) {
      interior.add(new HashSet<Vertex>());
      len.add(new HashMap<Vertex,Double>());
    }

    for (int i = 0; i <= n; i++) {
      // interior holds a list of vertices lying along path i;
      // len contains the distance of each vertex from path i's start point

      // See if student is on this path:
      Vertex p1 = new Vertex(x1[i],y1[i]);
      Vertex p2 = new Vertex(x2[i],y2[i]);
      if (Math.abs(triple(p1,p2,v.get(sid))) < EPS && xs >= Math.min(x1[i],x2[i])
          && ys >= Math.min(y1[i],y2[i]) && xs <= Math.max(x1[i],x2[i])
          && ys <= Math.max(y1[i],y2[i])) { // student is on this path
            Vertex stu = v.get(sid);
            if (!interior.get(i).contains(stu)) {
              interior.get(i).add(stu);
              len.get(i).put(stu,dist(x1[i],y1[i],stu.x,stu.y));
            };
          }
      for (int j = i+1; j <= n; j++) {
        double[] ai = inter(i,j);
        if (ai == null) continue; // no intersection
        Vertex vinter = new Vertex(ai[0],ai[1]);
        // See if this vertex is a new one, if so, add it to vertex list
        if (!vs.contains(vinter)) {
          vinter = new Vertex(vn,ai[0],ai[1]);
          vs.add(vinter);
          v.add(vinter);
          vn++;
        }

        else vinter = v.get(vinter.i);


        // See if intersection is already in nbr list of each path;
        // if not, indicate its distance from start of path.
        // NOTE: if vinter is a new vertex, "if" stmt gives it an id;
        // if it's an old vertex, the "equals" method assigns it the right id
        if (!interior.get(i).contains(vinter)) {
          Vertex temp = v.get(vinter.i);
          interior.get(i).add(temp);
          if (i < n) {
            len.get(i).put(temp,dist(x1[i],y1[i],ai[0],ai[1]));
          } else {
            len.get(i).put(temp,Double.MAX_VALUE);
          }
        }
        if (!interior.get(j).contains(vinter)) {
          Vertex temp = v.get(vinter.i);
          interior.get(j).add(temp);
          len.get(j).put(temp,dist(x1[j],y1[j],ai[0],ai[1]));
        }
      }
      // Sort vertices along path i and fill in distances:
      Vertex[] intera = new Vertex[interior.get(i).size()];
      intera = interior.get(i).toArray(intera);
      HashMap<Vertex,Double> hm = len.get(i);

      Arrays.sort(intera,new Comparator<Vertex>() {
            public int compare(Vertex a1, Vertex a2) {
                double diff = hm.get(a1)-hm.get(a2);
                if (diff > 0) return 1;
                else if (diff < 0) return -1;
                else return 0;
              }});
      // Add neighbors except on Fellow's path:
      if (i < n) {
      for (int k = 0; k < intera.length-1; k++) {
        Vertex a = v.get(intera[k].i);
        Vertex b = v.get(intera[k+1].i);
        a.nbr.add(b);
        b.nbr.add(a);
        double dis = dist(a,b);
        a.dist.put(b,dis);
        b.dist.put(a,dis);
      }
    }
    }
  pq = new PriorityQueue<Vertex>(new Comparator<Vertex>(){
            public int compare(Vertex a1, Vertex a2) {
              double diff = a1.bestdist-a2.bestdist;
              if (diff > 0) return 1;
                else if (diff < 0) return -1;
                else return 0;
              }
            } );
    visited = new boolean[v.size()];
    Arrays.fill(visited,false);
    v.get(sid).bestdist = 0;
    pq.add(v.get(sid));
    while (!pq.isEmpty()) {
      Vertex u = pq.poll();
      sssp(u);
    }
    double sol = Double.MAX_VALUE;
    int solv = -1;
    for (Vertex u:interior.get(n)) {
      double stime = u.bestdist/ss;
      double ftime = dist(v.get(0),u)/sf;
      if (stime <= ftime + EPS && ftime < sol) {
        solv = u.i;
        sol = ftime;
      }
    }
    if (solv >=0) {
    System.out.printf("%.8f\n",sol);
  } else {
    System.out.println("Impossible");
}
  }

  // triple product
  public static double triple(Vertex a, Vertex b, Vertex c) {
    return a.x*b.y+a.y*c.x+b.x*c.y-c.x*b.y-c.y*a.x-b.x*a.y;
  }

  // Intersect line segments a1--a2 and b1--b2, return point of intersection
  public static double[] inter(int i, int j) {
    Vertex a1 = new Vertex(x1[i],y1[i]);
    Vertex a2 = new Vertex(x2[i],y2[i]);
    Vertex b1 = new Vertex(x1[j],y1[j]);
    Vertex b2 = new Vertex(x2[j],y2[j]);
    // first, see if they share an endpoint:
    if (eq(a1.x,b1.x) && eq(a1.y,b1.y) ||
        eq(a1.x,b2.x) && eq(a1.y,b2.y)) return new double[]{a1.x,a1.y};
    if (eq(a2.x,b1.x) && eq(a2.y,b1.y) ||
        eq(a2.x,b2.x) && eq(a2.y,b2.y)) return new double[]{a2.x,a2.y};

    double t1 = triple(a1,a2,b1);
    double t2 = triple(a1,a2,b2);
    double t3 = triple(b1,b2,a1);
    double t4 = triple(b1,b2,a2);

    // Check for collinear:
    if (Math.abs(t1) < EPS && Math.abs(t2) < EPS && Math.abs(t3) < EPS &&
        Math.abs(t4) < EPS) {
      return null; // we are guaranteed no two paths overlap more than a point
    }

    // See if they intersect:
    if (t1*t2 <= 0 && t3*t4 <= 0) {// they intersect; find the point
      // Cramer's rule using parametric rep
      double p1 = a2.x-a1.x;
      double p2 = -(b2.x-b1.x);
      double q1 = a2.y-a1.y;
      double q2 = -(b2.y-b1.y);
      double c1 = b1.x-a1.x;
      double c2 = b1.y-a1.y;
      double denom = p1*q2-q1*p2;
      double s1 = (c1*q2-c2*p2)/denom;
      double s2 = (p1*c2-q1*c1)/denom;
      double x = a1.x+s1*(a2.x-a1.x);
      double y = a1.y+s1*(a2.y-a1.y);
      return new double[]{x,y};
    }
    return null; // no intersection
  }

  public static boolean eq(double a, double b) {
    return Math.abs(a-b) < EPS;
  }

  public static boolean samev(Vertex a, Vertex b) {
    return eq(a.x,b.x) && eq(a.y,b.y);
  }

  public static double dist(Vertex a, Vertex b) {
    return dist(a.x,a.y,b.x,b.y);
  }

  public static double dist(double x1, double y1, double x2, double y2) {
    return Math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
  }

  public static void sssp(Vertex u) {
    int ui = u.i;
    visited[ui] = true;
    for (Vertex w: u.nbr) {
      int wi = w.i;
       if (visited[wi]) continue;
       double newdist = u.bestdist + u.dist.get(w);
       if (w.bestdist > newdist) {
         w.parent = u.i;
         w.bestdist = newdist;
         pq.remove(w); // if it's there
         pq.add(w);
       }
     }
  }
}
