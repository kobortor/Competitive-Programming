#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

struct BIT {
    int data[MAXN];
    void update(int pos){
        while(pos < MAXN){
            data[pos]++;
            pos += pos & -pos;
        }
    }
    int query(int pos){
        int ans = 0;
        while(pos){
            ans += data[pos];
            pos -= pos & -pos;
        }
        return ans;
    }
} ds;

struct frac {
    ll u, v;
    int src;
    bool operator<(const frac &f) const {
        return u * f.v < v * f.u;
    }
};

int N;
frac orig[MAXN];
frac points[MAXN];
int out[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> points[a].v;
        cin >> points[a].u;
        points[a].src = a;
    }
    sort(points, points + N, [](frac a, frac b) { return a.v < b.v; });
    for(int a = 0; a < N; a++){
        orig[a] = points[a];
    }

    sort(points, points + N);

    for(int a = 0; a < N; a++){
        int id = lower_bound(points, points + N, orig[a]) - points + 1;
        out[orig[a].src] = ds.query(id);
        ds.update(id);
    }
    for(int a = 0; a < N; a++){
        cout << out[a] << "\n";
    }
}
