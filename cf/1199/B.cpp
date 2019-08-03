#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    double H, L;
    cin >> H >> L;
    cout << fixed << setprecision(10) << (L*L - H*H) / (2*H);
}
