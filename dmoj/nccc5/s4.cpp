#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, K;
vector<ll> spots;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    spots.push_back(0);
    for(int a = 0; a < K; a++){
        int x;
        cin >> x;
        spots.push_back(x);
    }
    spots.push_back(N + 1);

    ll ans = N * (N - 1) / 2 + N;

    //0 C
    for(int a = 1; a < K + 2; a++){
        ll len = spots[a] - spots[a - 1] - 1;
        ans -= len + len * (len - 1) / 2;
    }

    //1 C
    for(int a = 1; a < K + 1; a++){
        ans -= (spots[a] - spots[a - 1]) * (spots[a + 1] - spots[a]);
    }

    //2 C
    for(int a = 1; a < K; a++){
        ans -= (spots[a] - spots[a - 1]) * (spots[a + 2] - spots[a + 1]);
    }
    cout << ans;
}
