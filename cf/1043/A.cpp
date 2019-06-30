#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    int sum = 0, mx = 0;
    for (int a = 0, x; a < n; a++) {
        cin >> x;
        mx = max(mx, x);
        sum += x;
    }

    cout << max(mx, sum * 2 / n + 1);
}
