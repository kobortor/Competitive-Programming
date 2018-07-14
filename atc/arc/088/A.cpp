#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll X, Y;
    cin >> X >> Y;

    int ans = 0;
    while(X <= Y){
        X *= 2;
        ans++;
    }
    cout << ans;
}