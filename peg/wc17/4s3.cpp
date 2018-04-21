#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

ll N;
set<pii> row[MAXN];
set<pii> col[MAXN];

bool vis[MAXN];
ll ans = 0;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= N; b++){
            ll x;
            cin >> x;
            row[a].insert({x, b});
            col[b].insert({x, a});
        }
    }

    for(int a = 1; a <= N; a++){
        pii best = pii(2e9, 1);
        for(int b = 1; b <= N; b++){
            if(vis[b]){
                continue;
            }
            ll b1 = prev(row[b].end())->first;
            ll b2 = prev(col[b].end())->first;
            best = min(best, pii(min(b1, b2), b));
        }
        vis[best.second] = true;
        while(true){
            pii last = *prev(row[best.second].end());
            if(last.first > best.first){
                row[best.second].erase(last);
                col[last.second].erase(pii(last.first, best.second));

                ans += last.first - best.first;
                last.first = best.first;
                row[best.second].insert(last);
                col[last.second].insert(pii(last.first, best.second));
            } else {
                break;
            }
        }

        while(true){
            pii last = *prev(col[best.second].end());
            if(last.first > best.first){
                col[best.second].erase(last);
                row[last.second].erase(pii(last.first, best.second));

                ans += last.first - best.first;
                last.first = best.first;
                col[best.second].insert(last);
                row[last.second].insert(pii(last.first, best.second));
            } else {
                break;
            }
        }
    }
    cout << ans;

}
