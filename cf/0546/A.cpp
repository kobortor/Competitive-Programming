#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int k, n, w;
    cin >> k >> n >> w;

    cout << max(0, (w * (w + 1) / 2) * k - n);
}
