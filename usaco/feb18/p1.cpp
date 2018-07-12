#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 4e5 + 10;
const int BACK = 4e5 + 3;

int N, M;

struct cata {
    ll x, y, t;
};
vector<cata> pults;

ll out[MAXN];

struct query{
    ll x, y, id;
};
vector<query> queries;

vector<int> compress;
struct BIT {
    ll data[MAXN];
    void clear(){
        memset(data, 0x3f, sizeof data);
    }
    void update(int pos, ll val){
        pos = lower_bound(allof(compress), pos) - compress.begin();

        pos = pos + 2;
        while(pos < MAXN){
            data[pos] = min(data[pos], val);
            pos += pos & -pos;
        }
    }
    ll query(int pos){
        pos = lower_bound(allof(compress), pos) - compress.begin();

        pos = pos + 2;
        ll ans = 1e15;
        while(pos){
            ans = min(ans, data[pos]);
            pos -= pos & -pos;
        }
        return ans;
    }
} ds, ds_rev;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    freopen("slingshot.in", "r", stdin);
    freopen("slingshot.out", "w", stdout);

    cin >> N >> M;
    for(int a = 0; a < N; a++){
        cata c;
        cin >> c.x >> c.y >> c.t;
        
        compress.push_back(c.y);
        compress.push_back(BACK - c.y);

        pults.push_back(c);
    }

    for(int a = 0; a < M; a++){
        query q;
        cin >> q.x >> q.y;

        compress.push_back(q.y);
        compress.push_back(BACK - q.y);

        q.id = a;
        out[a] = abs(q.x - q.y);

        queries.push_back(q);
    }
    sort(allof(compress));
    compress.erase(unique(allof(compress)), compress.end());

    // <= x
    ds.clear();
    ds_rev.clear();
    sort(allof(queries), [](const query &qa, const query &qb){return qa.x < qb.x;});

    int idx = 0;
    sort(allof(pults), [](const cata &ca, const cata &cb){return ca.x < cb.x;});

    for(const query &q : queries){
        while(idx < (int)pults.size() && pults[idx].x <= q.x){
            ds.update(pults[idx].y, -pults[idx].x - pults[idx].y + pults[idx].t);
            ds_rev.update(BACK - pults[idx].y, -pults[idx].x + pults[idx].y + pults[idx].t);
            idx++;
        }

        out[q.id] = min(out[q.id], ds.query(q.y) + q.x + q.y);
        out[q.id] = min(out[q.id], ds_rev.query(BACK - q.y) + q.x - q.y);
    }

    // >= x
    ds.clear();
    ds_rev.clear();
    reverse(allof(queries));

    idx = 0;
    reverse(allof(pults));

    for(const query &q : queries){
        while(idx < (int)pults.size() && pults[idx].x >= q.x){
            ds.update(pults[idx].y, pults[idx].x - pults[idx].y + pults[idx].t);
            ds_rev.update(BACK - pults[idx].y, pults[idx].x + pults[idx].y + pults[idx].t);
            idx++;
        }

        out[q.id] = min(out[q.id], ds.query(q.y) - q.x + q.y);
        out[q.id] = min(out[q.id], ds_rev.query(BACK - q.y) - q.x - q.y);
    }


    for(int a = 0; a < M; a++){
        cout << out[a] << "\n";
    }
}
