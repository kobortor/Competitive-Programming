#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int cnt[10];
ll fact[20];
ll ans = 0;

void recur(int pos, int len, ll div){
    if(pos == 10){
        ll mult = fact[len] / div;

        if(cnt[0] == 0){
            ans += mult;
        } else {
            for(int a = 1; a <= cnt[0]; a++){
                ans += mult * (fact[len + a - 1] / fact[a] / fact[len - 1]);
            }
        }
        return;
    }

    if(cnt[pos] == 0){
        recur(pos + 1, len, div);
    } else {
        for(int a = 1; a <= cnt[pos]; a++){
            recur(pos + 1, len + a, div * fact[a]);
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    fact[0] = 1;
    for(int a = 1; a < 20; a++){
        fact[a] = fact[a - 1] * a;
    }

    string str;
    cin >> str;
    for(char c : str){
        cnt[c - '0']++;
    }

    recur(1, 0, 1);

    cout << ans;
}
