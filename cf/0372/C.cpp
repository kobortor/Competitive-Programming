#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1.5e5 + 5;

int N, M, D;

ll dp[2][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> D;

    ll prvtime = 0;
    while(M--){
        ll A, B, T;
        cin >> A >> B >> T;

        memset(dp[1], 0xaf, sizeof dp[1]);

        T -= prvtime;
        prvtime += T;

        deque<pll> dq;

        for(int a = 1; a <= N; a++){
            while(!dq.empty() && a - dq.front().first > D * T){
                dq.pop_front();
            }

            while(!dq.empty() && dq.back().second <= dp[0][a]){
                dq.pop_back();
            }

            dq.push_back({a, dp[0][a]});
            dp[1][a] = dq.front().second + B - abs(A - a);
        }

        dq.clear();
        
        for(int a = N; a >= 1; a--){
            while(!dq.empty() && dq.front().first - a > D * T){
                dq.pop_front();
            }

            while(!dq.empty() && dq.back().second <= dp[0][a]){
                dq.pop_back();
            }

            dq.push_back({a, dp[0][a]});
            dp[1][a] = max(dp[1][a], dq.front().second + B - abs(A - a));
        }

        memcpy(dp[0], dp[1], sizeof dp[1]);
    }

    cout << *max_element(dp[0] + 1, dp[0] + N + 1);
}
