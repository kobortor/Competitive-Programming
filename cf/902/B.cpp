#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e4 + 4;
vector<int> adj[MAXN];
int col[MAXN];

int solve(int pos, bool filled){
    int ans = !filled;
    for(int i : adj[pos]){
        ans += solve(i, col[pos] == col[i]);
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;
    for(int a = 2; a <= N; a++){
        int par;
        cin >> par;
        adj[par].push_back(a);
    }
    for(int a = 1; a <= N; a++) {
        cin >> col[a];
    }
    cout << solve(1, false);

}