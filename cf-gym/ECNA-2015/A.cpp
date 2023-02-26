#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct P
{
    
    ll mass;
    ll x, y, z;
    ll vx, vy, vz;

    P(ll _m, ll _x, ll _y, ll _z, ll _vx, ll _vy, ll _vz) {
        mass = _m;
        x = _x;
        y = _y;
        z = _z;
        vx = _vx;
        vy = _vy;
        vz = _vz;
    }

    P () {}

};

bool comp(P x, P y) {

    array<ll,4> repx = {-x.mass, x.x, x.y, x.z};
    array<ll,4> repy = {-y.mass, y.x, y.y, y.z};

    return (repx < repy);

}

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (!b) return x = 1, y = 0, a;
    ll d = euclid(b, a % b, y, x);
    return y -= a/b * x, d;
}

ll crt(ll a, ll m, ll b, ll n) {
    if (n > m) swap(a, b), swap(m, n);
    ll x, y, g = euclid(m, n, x, y);
    if ((a - b) % g != 0) return -1;
    assert((a - b) % g == 0);
    x = (b - a) % n * x % n / g * m + a;
    return x < 0 ? x + m*n/g : x;
}

// REQUIRES: 0 <= x1, d1, x2, d2 < n
// ENSURES: returns smallest t >= 0 such that 
//          (x1 - x2) = (d2 - d1) * t (mod n)
ll single_coord(ll x1, ll d1, ll x2, ll d2, ll n) {
    ll b = d2 - d1;
    b %= n, b += n, b %= n;
    ll c = n;
    ll a = x1 - x2;
    a %= n, a += n, a %= n;
    ll x, y;
    ll g = euclid(b, c, x, y);
    if (a % g != 0) return -1;
    x *= a / g, y *= a / g;
    int mult = c / g;
    x %= mult, x += mult, x %= mult;
    return x;

}

// REQUIRES: 0 <= t1, t2; 0 < q1, q2
// ENSURES: returns smallest x >= 0, where there exist k1, k2 such that 
//          t1 + k1 * q1 = t2 + k2 * q2 = x
ll merge(ll t1, ll q1, ll t2, ll q2) {
    t1 %= q1; t2 %= q2;
    return crt(t1, q1, t2, q2);

}

ll dn(ll x, ll y) {

    if (x < 0) {
        x = -(abs(x) % y);
    }

    x = (x + y) % y;
    return x;

}

ll ggcd(ll x, ll y) {
    if (!x) return y;
    if (!y) return x;
    return ggcd(y%x, x);
}

P dostuff(P x, ll n1, ll n2, ll n3) {

    x.vx = dn(x.vx, n1);
    x.vy = dn(x.vy, n2);
    x.vz = dn(x.vz, n3);

    return x;

}

ll collision_time(P a, P b, ll n1, ll n2, ll n3) {

    a = dostuff(a, n1, n2, n3);
    b = dostuff(b, n1, n2, n3);

    ll xv = single_coord(a.x, dn(a.vx, n1), b.x, dn(b.vx, n1), n1);
    ll yv = single_coord(a.y, dn(a.vy, n2), b.y, dn(b.vy, n2), n2);
    ll zv = single_coord(a.z, dn(a.vz, n3), b.z, dn(b.vz, n3), n3);

    if (xv == -1 || yv == -1 || zv == -1) return -1;

    ll qx = n1 / ggcd(n1, dn(b.vx - a.vx, n1));
    ll qy = n2 / ggcd(n2, dn(b.vy - a.vy, n2));
    ll qz = n3 / ggcd(n3, dn(b.vz - a.vz, n3));

    ll t1 = merge(xv, qx, yv, qy); ll L1 = (qx * qy) / ggcd(qx, qy);
    ll t2 = merge(yv, qy, zv, qz); ll L2 = (qy * qz) / ggcd(qy, qz);

    if (t1 == -1 || t2 == -1) return -1;

    return merge(t1, L1, t2, L2);

}

array<ll,3> get_pos(P foo) {
    return {foo.x, foo.y, foo.z};
}

array<ll,3> get_vel(P foo) {
    return {foo.vx, foo.vy, foo.vz};
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n; cin >> n;

    ll n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<P> a;
    for (ll i = 0; i < n; i++) {

        P curr;
        cin >> curr.mass >> curr.x >> curr.y >> curr.z >> curr.vx >> curr.vy >> curr.vz;
        // curr.vx = dn(curr.vx, n1);
        // curr.vy = dn(curr.vy, n2);
        // curr.vz = dn(curr.vz, n3);
        a.push_back(curr);

    }

    while (1) {

        ll ct = 1e18;

        n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                ll wt = collision_time(a[i], a[j], n1, n2, n3);
                if (wt != -1 && wt < ct) {

                    ct = wt;

                }

            }
        }

        if (ct > 9e17) break;

        for (int i = 0; i < n; i++) {

            a[i].x += (a[i].vx * ct); a[i].x = dn(a[i].x, n1);
            a[i].y += (a[i].vy * ct); a[i].y = dn(a[i].y, n2);
            a[i].z += (a[i].vz * ct); a[i].z = dn(a[i].z, n3);

        }

        vector<P> res;
        sort(a.begin(), a.end(), [&](P xx, P yy) {
            return get_pos(xx) < get_pos(yy);
        });

        while (a.size()) {

            array<ll,3> cpos = get_pos(a.back());
            ll tmass = a.back().mass;
            ll tcnt = 1;
            array<ll,3> tvel = get_vel(a.back());

            a.pop_back();

            while (a.size() && get_pos(a.back()) == cpos) {

                tcnt++;
                tmass += a.back().mass;

                array<ll,3> nvel = get_vel(a.back());
                a.pop_back();

                for (int j = 0; j < 3; j++) {
                    tvel[j] += nvel[j];
                }

            }

            for (int j = 0; j < 3; j++) {
                tvel[j] /= tcnt;
            }

            res.push_back(P(tmass, cpos[0], cpos[1], cpos[2], tvel[0], tvel[1], tvel[2]));

        }

        a = res;

    }

    sort(a.begin(), a.end(), comp);

    cout << a.size() << "\n";
    int ww = 0;
    for (P foo : a) {

        cout << "P" << ww << ": " << foo.mass << " " << foo.x << " " << foo.y << " " << foo.z << " " << foo.vx << " " << foo.vy << " " << foo.vz << "\n";
        ww++;

    }

}
