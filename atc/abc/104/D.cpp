#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

string S;
ll LA, LQ, RC, RQ;

ll pow3[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    pow3[0] = 1;
    for(int a = 1; a < MAXN; a++){
        pow3[a] = pow3[a - 1] * 3 % mod;
    }

    cin >> S;
    RC = count(allof(S), 'C');
    RQ = count(allof(S), '?');

    ll ans = 0;

    for(char c : S){
        RC -= c == 'C';
        RQ -= c == '?';

        if(c == 'B' || c == '?'){
            ll cntL = pow3[LQ] * LA % mod;
            if(LQ){
                cntL += LQ * pow3[LQ - 1] % mod;
            }

            ll cntR = pow3[RQ] * RC % mod;
            if(RQ){
                cntR += RQ * pow3[RQ - 1] % mod;
            }

            ans += (cntL % mod) * (cntR % mod);
            ans %= mod;
        }

        LA += c == 'A';
        LQ += c == '?';
    }

    cout << ans;
}
