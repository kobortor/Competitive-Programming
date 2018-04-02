#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

ll N, Q;
pll kings[MAXN];

vector<ll> uniqx, uniqy;

ll cntx[MAXN], costx[MAXN];
ll cnty[MAXN], costy[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> Q;

    for(int a = 1; a <= N; a++){
        ll x, y;
        cin >> x >> y;
        kings[a].first = x + y;
        kings[a].second = x - y;

        uniqx.push_back(kings[a].first);
        uniqy.push_back(kings[a].second);
    }
    
    uniqx.push_back(-3e10);
    uniqx.push_back(3e10);

    uniqy.push_back(-3e10);
    uniqy.push_back(3e10);
    
    sort(allof(uniqx));
    uniqx.erase(unique(allof(uniqx)), uniqx.end());
    
    sort(allof(uniqy));
    uniqy.erase(unique(allof(uniqy)), uniqy.end());

    for(int a = 1; a <= N; a++){
        int ux = lower_bound(allof(uniqx), kings[a].first) - uniqx.begin();
        int uy = lower_bound(allof(uniqy), kings[a].second) - uniqy.begin();

        cntx[ux]++;
        cnty[uy]++;
    }

    for(int a = 1; a < (int)uniqx.size(); a++){
        cntx[a] += cntx[a-1];
        costx[a] += costx[a-1];
        costx[a] += (uniqx[a] - uniqx[a-1]) * cntx[a-1];
    }

    for(int a = 1; a < (int)uniqy.size(); a++){
        cnty[a] += cnty[a-1];
        costy[a] += costy[a-1];
        costy[a] += (uniqy[a] - uniqy[a-1]) * cnty[a-1];
    }

    ll cx = 0;
    for(int a = (int)uniqx.size() - 2; a >= 0; a--){
        cx += (uniqx[a+1] - uniqx[a]) * (N - cntx[a]);
        costx[a] += cx;
    }

    ll cy = 0;
    for(int a = (int)uniqy.size() - 2; a >= 0; a--){
        cy += (uniqy[a+1] - uniqy[a]) * (N - cnty[a]);
        costy[a] += cy;
    }
    
    while(Q--){
        ll x, y;
        cin >> x >> y;
        ll ux = x + y;
        ll uy = x - y;

        ll px = upper_bound(allof(uniqx), ux) - uniqx.begin() - 1;
        ll py = upper_bound(allof(uniqy), uy) - uniqy.begin() - 1;

        ll ans = 0;

        ll dx = ux - uniqx[px];
        ll dy = uy - uniqy[py];

        ans += costx[px] + dx * (cntx[px] - (N - cntx[px]));
        ans += costy[py] + dy * (cnty[py] - (N - cnty[py]));

        cout << ans / 2 << "\n";
    }
}
