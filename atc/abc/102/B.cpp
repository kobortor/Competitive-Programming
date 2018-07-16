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

    int mn = 1e9, mx = 0;
    while(N--){
        int x;
        cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
    }

    cout << mx - mn;
}
