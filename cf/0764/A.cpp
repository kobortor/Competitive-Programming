#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll x, ll y){
    while(x % y){
        x %= y;
        swap(x, y);
    }

    return y;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll N, M, Z;
    cin >> N >> M >> Z;

    ll LCM = N * M / gcd(N, M);
    cout << Z / LCM << endl;

}
