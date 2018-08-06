#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, M;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    ll tot = 0;
    while(N--){
        ll x;
        cin >> x;

        cout << (tot + x) / M - tot / M << " ";
        tot += x;
    }
}
