#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll orig[14];
ll tmp[14];

ll score(int idx){
    memcpy(tmp, orig, sizeof tmp);
    int val = tmp[idx];
    if(val == 0){
        return -1;
    }
    tmp[idx] = 0;

    for(int a = 0; a < 14; a++){
        tmp[a] += val / 14;
    }
    val %= 14;
    for(int a = 1; a <= val; a++){
        tmp[(idx + a) % 14]++;
    }

    ll ans = 0;
    for(int a = 0; a < 14; a++){
        if(tmp[a] % 2 == 0){
            ans += tmp[a];
        }
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for(int a = 0; a < 14; a++) cin >> orig[a];

    ll ans = 0;
    for(int a = 0; a < 14; a++) ans = max(ans, score(a));

    cout << ans;
}
