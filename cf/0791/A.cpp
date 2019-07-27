#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int a, b;
    cin >> a >> b;

    int ans = 0;
    while (a <= b) {
        a *= 3;
        b *= 2;
        ans++;
    }

    cout << ans;
}
