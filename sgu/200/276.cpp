#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int s, p;
    cin >> s >> p;
    int late = p - s;
    if (late >= 30 * 60) cout << 4;
    else if (late >= 15 * 60) cout << 3;
    else if (late >= 5 * 60) cout << 2;
    else if (late > 0) cout << 1;
    else cout << 0;
}
