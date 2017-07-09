#include<bits/stdc++.h>

/*
Not sure if I'm the first person to use BITs in this way, but I haven't seen it in the wild before.
*/

using namespace std;
typedef long long ll;

const int MAXN = 500; //example

struct BIT {
    ll data[MAXN];
    BIT() {
        fill(data, data + MAXN, 0);
    }
    void update(int pos, ll val) {
        while(pos < MAXN) {
            data[pos] += val;
            pos += pos & -pos;
        }
    }
    ll query(int pos) {
        ll ans = 0;

        while(pos) {
            ans += data[pos];
            pos -= pos & -pos;
        }

        return ans;
    }
};

struct quadBIT {
    //constants, linear, quadratic
    BIT con, lin, quad;

    //adds v, 2v, 3v, 4v... to values in [l, r]
    void update(int l, int r, int v) {
        int s = l - 1; //start pos

        quad.update(l, v);
        quad.update(r + 1, -v);

        lin.update(l, v * (1 - 2 * s));
        lin.update(r + 1, -v * (1 - 2 * s));

        con.update(l, v * (s * s - s));
        con.update(r + 1, -v * (s * s - s));
        
        int len = r - l + 1;
        con.update(r+1, v * len * (len + 1));
    }

    ll query(ll x) {
        return (quad.query(x) * x * x + lin.query(x) * x + con.query(x)) / 2;
    }
    ll query(ll l, ll r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    quadBIT qb;
    
    //prints: 0   0   0   0   0   0   0   0   0   0
    for(int a = 1; a <= 10; a++) {
        printf("%-4i", qb.query(a,a));
    }
    printf("\n");
    
    qb.update(3, 5, 2);
    
    //prints: 0   0   2   4   6   0   0   0   0   0
    //diff:   0   0   +2  +4  +6  0   0   0   0   0
    for(int a = 1; a <= 10; a++) {
        printf("%-4i", qb.query(a,a));
    }
    printf("\n");
    
    qb.update(5, 7, 5);
    //prints: 0   0   2   4   11  10  15  0   0   0
    //diff:   0   0   0   0   +5  +10  +15  0   0   0
    for(int a = 1; a <= 10; a++) {
        printf("%-4i", qb.query(a,a));
    }
    printf("\n");
}
