#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    double d, l, v1, v2;
    cin >> d >> l >> v1 >> v2;

    cout << fixed << setprecision(10) << (l - d) / (v1 + v2);
}
