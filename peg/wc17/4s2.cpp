#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

typedef priority_queue<pii, vector<pii>, greater<pii>> minheap;

int N, M;
vector<int> adj[MAXN];
vector<int> radj[MAXN];

int best1[MAXN];
int best2[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    while(M--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    
    minheap pq1, pq2;

    memset(best1, 0x3f, sizeof best1);
    memset(best2, 0x3f, sizeof best2);

    best1[1] = 0;
    best2[1] = 0;

    pq1.push(pii(0, 1));
    pq2.push(pii(0, 1));
    
    while(!pq1.empty()){
        pii top = pq1.top();
        pq1.pop();

        for(int i : adj[top.second]){
            if(best1[i] > top.first + 1){
                best1[i] = top.first + 1;
                pq1.push(pii(top.first + 1, i));
            }
        }
    }

    while(!pq2.empty()){
        pii top = pq2.top();
        pq2.pop();

        for(int i : radj[top.second]){
            if(best2[i] > top.first + 1){
                best2[i] = top.first + 1;
                pq2.push(pii(top.first + 1, i));
            }
        }
    }

    int S;
    cin >> S;

    ll ans = 0;
    while(S--){
        int x;
        cin >> x;
        if(best1[x] > 1e9 || best2[x] > 1e9){
            cout << -1;
            return 0;
        }
        ans += best1[x] + best2[x];
    }
    cout << ans;
}
