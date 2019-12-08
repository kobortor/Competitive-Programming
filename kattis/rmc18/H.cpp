#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll Q, M, S, L;
    cin >> Q >> M >> S >> L;

    ll t1 = (Q * L + S + M - 1) / M;
    ll t2 = (L + M - 1) / M * Q;

    cout << max(t1, t2);
}
