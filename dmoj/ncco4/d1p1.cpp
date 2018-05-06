#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    while(N--){
        ll x;
        cin >> x;
        pq.push(x);
    }

    ll ans = 0;
    while((int)pq.size() > 1){
        ll v1 = pq.top(); pq.pop();
        ll v2 = pq.top(); pq.pop();

        ans += v1 + v2;
        pq.push(v1 + v2);
    }
    cout << ans << "\n";
}
