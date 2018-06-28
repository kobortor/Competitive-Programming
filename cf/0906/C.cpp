#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int cover[22];
int N, M;

int dp[1 << 22];
int prv[1 << 22];
int mv[1 << 22];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N >> M;

    for(int a = 0; a < N; a++){
        cover[a] |= 1 << a;
    }
    while(M--) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        cover[u] |= (1 << v);
        cover[v] |= (1 << u);
    }
    memset(dp, 0x3f, sizeof dp);
    memset(mv, -1, sizeof mv);
    memset(prv, -1, sizeof prv);

    //basically a hardcode case
    bool already_clique = true;
    for(int a = 0; a < N; a++){
        if(cover[a] != (1 << N) - 1){
            already_clique = false;
        }
    }
    if(already_clique){
        cout << "0\n";
        return 0;
    }

    for(int a = 0; a < N; a++){
        dp[1 << a] = 0;
    }

    for(int a = 0; a < (1 << N); a++){
        for(int b = 0; b < N; b++){
            if(a & (1 << b)){ //can use
                int newcost = dp[a] + 1;
                if(newcost < dp[a | cover[b]]){
                    dp[a | cover[b]] = newcost;
                    prv[a | cover[b]] = a;
                    mv[a | cover[b]] = b;
                }
            }
        }
    }

    vector<int> ans;
    int idx = (1 << N) - 1;
    while(mv[idx] != -1){
        ans.push_back(mv[idx] + 1);
        idx = prv[idx];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int i : ans){
        cout << i << " ";
    }
}
