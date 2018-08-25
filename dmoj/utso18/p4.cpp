#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXV = 1e5 + 5;

int N;
vector<int> coupon[MAXV];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        int k, m;
        cin >> k >> m;
        coupon[k + m].push_back(k);
    }

    ll ans = 0;
    for(int a = 0; a < MAXV; a++){
        ll K = 0;
        ll M = 0;

        sort(allof(coupon[a]));
        for(int i : coupon[a]){
            K += i;
        }

        for(int i : coupon[a]){
            K -= i;
            M += a - i;
            ans = max(ans, min(K, M));
        }
    }
    cout << ans;
}
