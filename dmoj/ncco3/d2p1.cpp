#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5e4 + 4;
pii sparse[MAXN][20];

int query(int ai, int bi){
    int lvl = 0;
    while(ai + (2 << lvl) - 1 <= bi){
        lvl++;
    }
    pii p1 = sparse[ai][lvl];
    pii p2 = sparse[bi - (1 << lvl) + 1][lvl];
    return max(p1.second, p2.second) - min(p1.first, p2.first);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for(int a = 0; a < MAXN; a++){
        fill(sparse[a], sparse[a] + 20, pii(2000000, -1));
    }

    int N, Q;
    cin >> N >> Q;
    for(int a = 1; a <= N; a++){
        cin >> sparse[a][0].first;
        sparse[a][0].second = sparse[a][0].first;
    }

    for(int lvl = 1; lvl < 20; lvl++){
        for(int a = 1; a + (1 << lvl) - 1 <= N; a++){
            pii p1 = sparse[a][lvl - 1];
            pii p2 = sparse[a + (1 << (lvl - 1))][lvl - 1];

            sparse[a][lvl] = pii(min(p1.first, p2.first), max(p1.second, p2.second));
        }
    }
    
    while(Q--){
        int ai, bi;
        cin >> ai >> bi;
        cout << query(ai, bi) << "\n";
    }
}
