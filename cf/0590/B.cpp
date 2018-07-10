#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll X1, Y1, X2, Y2;
ll V, T;

ll VX, VY, WX, WY;

ll DX, DY;

double getpos(double tm){
    double px = DX - min((double)T, tm) * VX - max(0.0, tm - T) * WX;
    double py = DY - min((double)T, tm) * VY - max(0.0, tm - T) * WY;
    return sqrt(px * px + py * py);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> X1 >> Y1 >> X2 >> Y2;
    cin >> V >> T;
    cin >> VX >> VY;
    cin >> WX >> WY;

    DX = X2 - X1;
    DY = Y2 - Y1;

    double lo, hi;
    if(getpos(T) <= V * T){
        lo = 0, hi = T;
    } else {
        lo = T;
        hi = 1e9;
    }

    for(int step = 0; step < 50; step++){
        double mid = (lo + hi) / 2;
        if(getpos(mid) <= V * mid){
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << fixed << setprecision(10) << lo;
}
