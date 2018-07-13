#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

const int MAXN = 205;

ll pow2[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    pow2[0] = 1;
    for(int a = 1; a < MAXN; a++){
        pow2[a] = pow2[a - 1] * 2 % mod;
    }

    string str;
    cin >> str;

    int N = str.size();

    ll ans = 0;

    for(int a = 0; a < N; a++){
        if(str[a] == '1'){
            ans = (ans + pow2[N - 1] * pow2[N - a - 1]) % mod;
        }
    }
    
    cout << ans;
}
