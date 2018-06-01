#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M;
set<int> miss[20];

ll tri(ll n){
    return n * (n + 1) / 2;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    for(int a = 0; a <= N + 1; a++){
        ll x = 0;
        if(1 <= a && a <= N){
            cin >> x;
        }

        for(int b = 0; b < 20; b++){
            if(!(x & (1 << b))){
                miss[b].insert(a);
            }
        }
    }

    ll ans = 0;
    for(int a = 1; a <= N; a++){
        for(int b = 0; b < 20; b++){
            auto iter = miss[b].lower_bound(a);
            if(*iter != a && *prev(iter) == a - 1){
                int wid = *iter - *prev(iter) - 1;
                ans += tri(wid) << b;
            }
        }
    }

    while(M--){
        int P, V;
        cin >> P >> V;

        //remove
        for(int b = 0; b < 20; b++){
            auto iter = miss[b].lower_bound(P);
            if(*iter != P){
                int before = *prev(iter);
                int after = *iter;

                int widT = after - before - 1;
                int widL = P - before - 1;
                int widR = after - P - 1;

                ans -= tri(widT) << b;
                ans += tri(widL) << b;
                ans += tri(widR) << b;
            } else {
                miss[b].erase(iter);
            }
        }

        //add
        for(int b = 0; b < 20; b++){
            if(V & (1 << b)){
                auto iter = miss[b].lower_bound(P);

                int before = *prev(iter);
                int after = *iter;

                int widT = after - before - 1;
                int widL = P - before - 1;
                int widR = after - P - 1;

                ans += tri(widT) << b;
                ans -= tri(widL) << b;
                ans -= tri(widR) << b;
            } else {
                miss[b].insert(P);
            }
        }

        cout << ans << "\n";
    }
}
