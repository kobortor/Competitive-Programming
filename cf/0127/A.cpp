#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
 
    int n, k;
    cin >> n >> k;
 
    double cost = 0;
    pii pos;
    cin >> pos.first >> pos.second;
 
    for (int a = 1; a < n; a++) {
        pii npos;
        cin >> npos.first >> npos.second;
 
        cost += hypot(npos.first - pos.first, npos.second - pos.second);
        pos = npos;
    }
 
    cout << fixed << setprecision(10) << cost * k / 50.0;
}
