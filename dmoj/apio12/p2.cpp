#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N, K, M;
vector<pii> guards;

int arr[MAXN];
bool req[MAXN];
int range[MAXN];
int nxt[MAXN], prv[MAXN];
int dp[MAXN];
int cost[MAXN];
int id[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K >> M;

    while(M--){
        int u, v, c;
        cin >> u >> v >> c;
        if(c == 0){
            arr[u]++;
            arr[v + 1]--;
        } else {
            guards.push_back({u, v});
        }
    }

    int cnt = 1;
    for(int a = 1; a <= N; a++){
        arr[a] += arr[a - 1];
        if(arr[a] == 0){
            id[cnt] = a;
            prv[a] = nxt[a] = cnt;
            for(int b = a - 1; arr[b] != 0; b--){
                nxt[b] = cnt;
            }

            cnt++;
        } else {
            prv[a] = cnt - 1;
        }
    }

    if(cnt == K + 1){
        for(int a = 1; a <= N; a++){
            if(arr[a] == 0){
                cout << a << "\n";
            }
        }
        return 0;
    }

    N = cnt - 1;

    fill(range + 1, range + N + 1, N + 1);

    for(pii p : guards){
        int l = nxt[p.first];
        int r = prv[p.second];

        range[l] = min(range[l], r);
    }

    for(int a = 1, minv = INT_MAX, curcost = 0; a <= N; a++){
        cost[a] = curcost;
        minv = min(minv, range[a]);

        if(minv == a){
            req[a] = true;
            curcost++;
            minv = INT_MAX;
            cost[a]++;
        } else if (minv != INT_MAX){
            cost[a]++;
        }
    }

    dp[N + 2] = -1;

    vector<pii> vec;
    vec.push_back({N + 2, -1});
    for(int a = N; a >= 1; a--){
        int rhs = range[a];

        while(rhs <= vec.back().second){
            vec.pop_back();
        }
        vec.push_back({a, rhs});

        int minv = lower_bound(allof(vec), pii(rhs, INT_MAX), greater<pii>())->second;

        dp[a] = dp[minv + 1] + 1;
    }

    bool printed = false;
    for(int a = 1; a <= N; a++){
        if(!req[a]){
            continue;
        }
        if(range[a] == a || dp[a] + cost[a - 1] > K){
            cout << id[a] << "\n";
            printed = true;
        }
    }
    if(!printed){
        cout << "-1\n";
    }
}
