#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    vector<int> v;

    ll sum = 0;
    ll mx = 0;
    for (int a = 0; a < N; a++) {
        ll x;
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }

    cout << mx * N - sum;
}
