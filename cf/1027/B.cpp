#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, Q;

//Extremely ugly!!!
ll solve(ll r, ll c){
    ll even = (r - 1 + (N & 1)) / 2;
    ll sum = even * ((N + (N & 1)) / 2) + (r - even - 1) * (N / 2) + (c + (r & 1)) / 2;
    if((r + c) % 2 == 0){
        return sum;
    } else {
        return (r - 1) * N + c - sum + (N * N + 1) / 2;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> Q;

    while(Q--){
        ll r, c;
        cin >> r >> c;
        cout << solve(r, c) << "\n";
    }
}
