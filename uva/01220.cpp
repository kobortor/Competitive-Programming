#include<bits/stdc++.h>

using namespace std;
template<typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using maxheap = priority_queue<T>;
template<typename T>
using dpair = pair<T, T>;
typedef long long ll;

const int MAXN = 205;
int N;
string name[MAXN];
string boss[MAXN];
vector<int> adj[MAXN];

//dp[*][0] is when not picking
//dp[*][1] is when definitely picking
int dp[MAXN][2];
bool uniq[MAXN][2];

void dfs(int pos) {
    uniq[pos][0] = uniq[pos][1] = true;

    for(int i : adj[pos]) {
        dfs(i);
    }

    //try picking this
    dp[pos][1] = 1;

    for(int i : adj[pos]) {
        uniq[pos][1] &= uniq[i][0];
        dp[pos][1] += dp[i][0];
    }

    //try not picking this
    dp[pos][0] = 0;

    for(int i : adj[pos]) {
        if(dp[i][0] == dp[i][1]) {
            uniq[pos][0] = false;
            dp[pos][0] += dp[i][0];
        } else if(dp[i][0] > dp[i][1]) {
            dp[pos][0] += dp[i][0];
            uniq[pos][0] &= uniq[i][0];
        } else { //assume dp[i][1] > dp[i][0]
            dp[pos][0] += dp[i][1];
            uniq[pos][0] &= uniq[i][1];
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif

    while(1) {
        cin >> N;

        if(N == 0) {
            break;
        }

        cin >> name[0];

        for(int a = 1; a < N; a++) {
            cin >> name[a] >> boss[a];
        }

        for(int a = 1; a < N; a++) {
            for(int b = 0; b < N; b++) {
                if(boss[a] == name[b]) {
                    adj[b].push_back(a);
                }
            }
        }

        dfs(0);

        bool isUniq = true;

        if(dp[0][0] == dp[0][1]) {
            isUniq = false;
        } else if(dp[0][0] > dp[0][1]) {
            isUniq = uniq[0][0];
        } else {
            isUniq = uniq[0][1];
        }

        cout << max(dp[0][0], dp[0][1]) << " " << (isUniq ? "Yes\n" : "No\n");

        for(int a = 0; a < N; a++) {
            adj[a].clear();
        }
    }
}
