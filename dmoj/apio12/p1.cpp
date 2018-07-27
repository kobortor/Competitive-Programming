#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M;
int leader[MAXN];
int sum[MAXN];
priority_queue<int> pq[MAXN];
vector<int> adj[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 1; a <= N; a++){
        int abv;
        cin >> abv >> sum[a] >> leader[a];
        pq[a].push(sum[a]);
        adj[abv].push_back(a);
    }

    ll ans = 0;
    for(int a = N; a >= 1; a--){
        for(int i : adj[a]){
            if(pq[i].size() > pq[a].size()){
                pq[a].swap(pq[i]);
                swap(sum[a], sum[i]);
            }
        }

        for(int i : adj[a]){
            while(!pq[i].empty()){
                sum[a] += pq[i].top();
                pq[a].push(pq[i].top());
                pq[i].pop();

                if(sum[a] > M){
                    sum[a] -= pq[a].top();
                    pq[a].pop();
                }
            }
        }

        ans = max(ans, (ll)leader[a] * (ll)pq[a].size());
    }
    cout << ans;
}
