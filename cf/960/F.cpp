#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M;
set<pii> best[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 1; a <= N; a++){
        best[a].insert(pii(-1, 0));
    }
    while(M--){
        int u, v, c;
        cin >> u >> v >> c;

        auto i1 = prev(best[u].lower_bound(pii(c, -1)));
        pii np = pii(c, i1->second + 1);

        auto i2 = prev(best[v].lower_bound(pii(c, -1)));
        if(i2->second >= np.second){
            //bad
        } else {
            i2++;
            while(i2 != best[v].end()){
                if((i2->first == np.first && i2->second < np.second) || (i2->first > np.first && i2->second <= np.second)){
                    auto tmp = i2;
                    i2++;
                    best[v].erase(tmp);
                } else {
                    break;
                }
            }
            best[v].insert(np);
        }
    }
    int ans = 0;
    for(int a = 1; a <= N; a++){
        ans = max(ans, prev(best[a].end())->second);
    }
    cout << ans;
}
