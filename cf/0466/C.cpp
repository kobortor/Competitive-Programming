#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5e5 + 5;

int N;
ll prefix[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> prefix[a];
        prefix[a] += prefix[a-1];
    }
    if(prefix[N] % 3 != 0){
        cout << 0;
        return 0;
    }
    ll targ = prefix[N] / 3;

    ll ans = 0;

    for(int a = 1, good = 0; a <= N; a++){
        if(prefix[N] - prefix[a - 1] == targ){
            ans += good;
        }
        if(a != 1 && prefix[a - 1] == targ){
            good++;
        }
    }
    cout << ans;
}
