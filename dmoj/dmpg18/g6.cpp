#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

template<class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

int N, C, K;

vector<int> stu[MAXN];
vector<pll> cls[MAXN];
vector<ll> taken[MAXN];
ll vi[MAXN]; //vim lmao

ll best[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> C >> K;
    for(int a = 1; a <= N; a++){
        cin >> vi[a];
    }
    for(int a = 1; a <= N; a++){
        int ci;
        cin >> ci;
        while(ci--){
            int x;
            cin >> x;
            stu[a].push_back(x);
            cls[x].push_back({vi[a], a});
        }
    }
    for(int a = 1; a <= C; a++){
        sort(allof(cls[a]));
        for(int b = 0; b < (int)cls[a].size(); b++){
            taken[a].push_back(LLONG_MAX);
        }
    }

    for(int a = 0; a < MAXN; a++){
        best[a] = LLONG_MAX;
    }

    best[1] = 0;
    minheap<pll> pq;
    pq.push(pll(0, 1));

    while(!pq.empty()){
        pll top = pq.top();
        pq.pop();

        for(int i : stu[top.second]){
            int idx = lower_bound(allof(cls[i]), pll(vi[top.second], top.second)) - cls[i].begin();
            for(int a = idx - 1; a >= 0; a--){
                ll cost = top.first + abs(vi[top.second] - cls[i][a].first) + K;

                if(cost >= taken[i][a]){
                    break;
                } else {
                    taken[i][a] = cost;
                }

                if(cost < best[cls[i][a].second]){
                    best[cls[i][a].second] = cost;
                    pq.push(pll(cost, cls[i][a].second));
                }
            }
            for(int a = idx + 1; a < (int)cls[i].size(); a++){
                ll cost = top.first + abs(vi[top.second] - cls[i][a].first) + K;
                if(cost >= taken[i][a]){
                    break;
                } else {
                    taken[i][a] = cost;
                }
                if(cost < best[cls[i][a].second]){
                    best[cls[i][a].second] = cost;
                    pq.push(pll(cost, cls[i][a].second));
                }
            }
        }
    }
    for(int a = 1; a <= N; a++){
        if(best[a] == best[0]){
            cout << -1 << "\n";
        } else {
            cout << best[a] << "\n";
        }
    }

}
