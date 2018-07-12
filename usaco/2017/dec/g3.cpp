#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

ll N, M;
ll flav[MAXN];
int spice[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);

    cin >> N >> M;

    for(int a = 1; a <= N; a++){
        cin >> flav[a];
        cin >> spice[a];
    }

    int ans = 2e9;

    deque<pii> dq;
    ll sum = 0;
    for(int a = 1, back = 1; a <= N; a++){
        sum += flav[a];
        while(sum - flav[back] >= M){
            sum -= flav[back++];
        }

        while(!dq.empty() && dq.front().first < back){
            dq.pop_front();
        }

        while(!dq.empty() && dq.back().second <= spice[a]){
            dq.pop_back();
        }

        dq.push_back({a, spice[a]});

        if(sum >= M){
            ans = min(ans, dq.front().second);
        }
    }

    cout << ans;
}
