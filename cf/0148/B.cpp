#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int VP, VD, T, F, C;
    cin >> VP >> VD >> T >> F >> C;

    if(VP >= VD){
        cout << 0;
        return 0;
    }

    double pos = VP * T;
    pos += VP * (pos / (VD - VP));

    int ans = 0;

    while(pos < C){
        ans++;

        double tm = pos / VD + F;
        tm += (pos + tm * VP) / (VD - VP);

        pos += VP * tm;
    }

    cout << ans;
}
