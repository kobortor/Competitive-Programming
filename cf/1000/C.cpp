#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    map<ll, ll> mp, ans;

    for(int a = 1; a <= N; a++){
        ll l, r;
        cin >> l >> r;
        mp[l]++;
        mp[r + 1]--;
    }

    ll cnt = 0;
    ll prv = 0;
    for(pll p : mp){
        ans[cnt] += p.first - prv;
        cnt += p.second;
        prv = p.first;
    }

    for(int a = 1; a <= N; a++){
        cout << ans[a] << " ";
    }
}
