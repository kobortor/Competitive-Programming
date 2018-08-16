#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;
map<int, int> freq;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    freq[0] = 1;

    ll ans = 0;

    for(int a = 1, tot = 0; a <= N; a++){
        int x;
        cin >> x;

        tot = (tot + x) % M;
        ans += freq[tot]++;
    }

    cout << ans;
}
