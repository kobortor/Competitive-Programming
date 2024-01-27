#include<bits/stdc++.h>
 
using namespace std;
 
#define allof(x) (x).begin(), (x).end()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
 
 
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
 
    ll n, k;
    cin >> n >> k;
 
    vector<pii> movies(n);
    for (pii &p : movies) {
        cin >> p.second >> p.first;
    }
 
    multiset<int> busy;
    for (int i = 0; i < k; i++) {
        busy.insert(-1e9);
    }
    sort(allof(movies));
    ll ans = 0;
 
    for (pii p : movies) {
        ll r = p.first;
        ll l = p.second;
 
        auto iter = busy.upper_bound(l);
        if (iter != busy.begin()) {
            int maxl = *prev(iter);
            busy.erase(prev(iter));
            busy.insert(r);
            ans++;
        }
    }
 
    cout << ans << endl;
}

