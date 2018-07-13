#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

ll N, D;

struct pie {
    int src, targ, tp;

    bool operator<(const pie &p) const {
        if(targ == p.targ){
            return tp < p.tp;
        } else {
            return targ > p.targ;
        }
    }
};

set<pie> pies[2];
queue<pair<int, pie>> q;
int ans[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(ans, -1, sizeof ans);

    freopen("piepie.in", "r", stdin);
    freopen("piepie.out", "w", stdout);

    cin >> N >> D;

    for(int a = 1; a <= N; a++){
        pie p;
        cin >> p.src >> p.targ;
        p.tp = a;

        if(p.targ == 0){
            q.push({1, p});
        } else {
            pies[0].insert(p);
        }
    }

    for(int a = 1; a <= N; a++){
        pie p;
        cin >> p.targ >> p.src;
        p.tp = -a;

        if(p.targ == 0){
            q.push({1, p});
        } else {
            pies[1].insert(p);
        }
    }

    while(!q.empty()){
        int dist = q.front().first;
        pie p = q.front().second;
        q.pop();

        if(p.tp > 0){
            ans[p.tp] = dist;
        }

        int nxt = p.tp > 0 ? 1 : 0;
        pie first;
        first.targ = p.src;
        first.tp = INT_MIN;
        auto iter = pies[nxt].lower_bound(first);
        while(iter != pies[nxt].end() && p.src - iter->targ <= D){
            q.push({dist + 1, *iter});
            auto tmp = iter;
            iter++;
            pies[nxt].erase(tmp);
        }
    }

    for(int a = 1; a <= N; a++){
        cout << ans[a] << "\n";
    }
}
