#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
map<int, vector<int>> hor, ver;
pii coord[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> coord[a].first;
        cin >> coord[a].second;
        hor[coord[a].first].push_back(coord[a].second);
        ver[coord[a].second].push_back(coord[a].first);
    }

    for(auto &au : hor){
        sort(allof(au.second));
    }
    for(auto &au : ver){
        sort(allof(au.second));
    }

    ll ans = 0;
    for(int a = 0; a < N; a++){
        int x = coord[a].first;
        int y = coord[a].second;
        int lessx = lower_bound(allof(hor[x]), y) - hor[x].begin();
        int lessy = lower_bound(allof(ver[y]), x) - ver[y].begin();

        int morex = hor[x].size() - lessx - 1;
        int morey = ver[y].size() - lessy - 1;

        ans += 2ll * lessx * lessy * morex * morey;
    }
    cout << ans;
}
