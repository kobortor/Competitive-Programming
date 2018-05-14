#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, W;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> W;
    int lo = 0, hi = W;
    int delta = 0;
    for(int a = 0; a < N; a++){
        int x;
        cin >> x;
        delta += x;
        lo = max(lo, -delta);
        hi = min(hi, W - delta);
    }
    cout << max(0, hi - lo + 1);
}
