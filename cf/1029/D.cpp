#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int numdig(ll x){
    int ans = 0;
    while(x){
        ans++;
        x /= 10;
    }
    return ans;
}

ll N, K;
ll concat(ll x, ll y){
    return stoull(to_string(x) + to_string(y)) % K;
}

ll arr[MAXN];
ll cat[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    ll ans = 0;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];

        if(concat(arr[a], arr[a]) % K == 0){
            ans--;
        }

        cat[a] = arr[a];
    }

    for(int d = 1; d <= 10; d++){
        map<ll, ll> mp;
        for(int a = 1; a <= N; a++){
            cat[a] = (cat[a] * 10) % K;
            mp[cat[a]]++;
        }

        for(int a = 1; a <= N; a++){
            if(numdig(arr[a]) == d){
                ans += mp[((-arr[a]) % K + K) % K];
            }
        }
    }
    cout << ans;
}
