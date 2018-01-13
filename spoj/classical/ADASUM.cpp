#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

string str;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> str;

    ll ans = 0;
    ll ones = 0;
    for(int a = (int)str.size() - 1; a >= 0; a--){
        ones = (ones * 10 + 1) % mod;
        ans += (a + 1) * ones * (str[a] - '0');
        ans %= mod;
    }
    cout << ans;
}
