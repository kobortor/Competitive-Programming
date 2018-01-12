#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;
const ll mod = 1e9 + 7;

string str;
int freq[MAXN][26];
ll fact[MAXN];

ll qpow(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y % 2) {
            ans = ans * x % mod;
        }
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    fact[0] = 1;
    for(int a = 1; a < MAXN; a++){
        fact[a] = fact[a - 1] * a % mod;
    }

    cin >> str;
    for(int a = 1; a <= (int)str.size(); a++){
        for(int b = 0; b < 26; b++){
            freq[a][b] = freq[a - 1][b];
        }
        freq[a][str[a - 1] - 'a']++;
    }
    int Q;
    cin >> Q;

    while(Q--){
        int l, r;
        cin >> l >> r;

        int mfreq[26];
        for(int a = 0; a < 26; a++){
            mfreq[a] = freq[r][a] - freq[l - 1][a];
        }

        int numodd = 0;
        int numeven = 0;
        for(int a = 0; a < 26; a++){
            numeven += mfreq[a] / 2;
            if(mfreq[a] % 2){
                numodd++;
            }
        }
        ll ans = fact[numeven];
        if(numodd > 0){
            ans = ans * numodd % mod;
        }
        for(int a = 0; a < 26; a++){
            int even = mfreq[a] / 2;
            if(even > 0){
                ans = ans * qpow(fact[even], mod - 2) % mod;
            }
        }
        cout << ans << "\n";
    }
}