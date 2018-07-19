#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1.1e6 + 6;

int M;
int arr[MAXN];
vector<int> block[MAXN];
set<int> rht[2 * MAXN];
int nxt_less[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> M;
    for(int a = 1; a <= M; a++){
        cin >> arr[a];
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int a = M; a >= 1; a--){
        pq.push({arr[a], a}); rht[arr[a] - a + MAXN].insert(a);

        while(pq.top().first < arr[a]){
            block[a].push_back(pq.top().second);
            int i = pq.top().second;
            rht[arr[i] - i + MAXN].erase(i);
            pq.pop();
        }
    }

    priority_queue<pii> pq2;
    for(int a = 1; a <= M; a++){
        nxt_less[a] = M + 1;

        pq2.push({arr[a], a});
        while(pq2.top().first > arr[a]){
            nxt_less[pq2.top().second] = a;
            pq2.pop();
        }
    }

    vector<pii> tmpans;
    for(int a = 1; a <= M; a++){
        for(int i : block[a]){
            rht[arr[i] - i + MAXN].insert(i);
        }

        auto iter = rht[arr[a] - a + MAXN].upper_bound(a);

        if(iter != rht[arr[a] - a + MAXN].end() && *iter <= nxt_less[a]){
            tmpans.push_back({a, *iter});
        }
    }

    while(!pq.empty()){
        pq.pop();
    }

    for(pii p : tmpans){
        pq.push({p.second, p.first});
    }

    vector<pii> ans;
    for(pii p : tmpans){
        while(!pq.empty() && pq.top().second <= p.first){
            pq.pop();
        }

        if(pq.empty() || pq.top().first > p.second){
            ans.push_back(p);
        }
    }
    
    cout << ans.size() << "\n";
    for(pii p : ans){
        cout << p.first << " " << p.second << "\n";
    }
}
