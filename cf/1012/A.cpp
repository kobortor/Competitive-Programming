#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
vector<int> vec;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < 2 * N; a++){
        int x;
        cin >> x;
        vec.push_back(x);
    }

    sort(allof(vec));

    ll ans = (ll)(vec[N - 1] - vec[0]) * (vec[2 * N - 1] - vec[N]);
    for(int a = N; a + 1 < 2 * N; a++){
        ans = min(ans, (ll)(vec[a] - vec[a - N + 1]) * (vec[2 * N - 1] - vec[0]));
    }
    cout << ans;
}
