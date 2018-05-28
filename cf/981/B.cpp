#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;
map<int, pii> mp;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    while(N--){
        int a, x;
        cin >> a >> x;
        mp[a].first = x;
    }

    cin >> M;
    while(M--){
        int a, x;
        cin >> a >> x;
        mp[a].second = x;
    }

    ll ans = 0;
    for(auto au : mp){
        ans += max(au.second.first, au.second.second);
    }
    cout << ans;
}
