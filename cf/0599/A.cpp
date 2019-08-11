#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int d1, d2, d3;
    cin >> d1 >> d2 >> d3;

    d1 = min(d1, d2 + d3);
    d2 = min(d2, d1 + d3);
    d3 = min(d3, d1 + d2);

    cout << d1 + d2 + d3;
}
