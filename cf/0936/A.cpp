#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll K, D, T;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> K >> D >> T;
    T = 2 * T;

    //cook for K
    ll cycle = 2 * K + (D - K % D) % D;
    ll tm = (K + D - 1) / D * D;
    double ans = tm * (T / cycle);
    T %= cycle;
    
    if(T <= 2 * K){
        ans += T / 2.0;
    } else {
        T -= 2 * K;
        ans += K;
        ans += T;
    }
    cout << fixed << setprecision(15) << ans;
}
