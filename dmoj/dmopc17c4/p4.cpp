#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

int N;
vector<int> blocked[MAXN];
queue<int> avail;

priority_queue<pll> pq;

int out[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int last_block = -1;

    cin >> N;

    for(int a = 1; a <= N; a++){
        cin >> last_block;
        blocked[last_block].push_back(a);
    }
    for(int a = 1; a <= N; a++){
        pq.push(pll(blocked[a].size(), a));
    }
    pll p1 = pq.top();
    pq.pop();
    if(p1.first == N){
        cout << -1;
        return 0;
    }

    for(int i : blocked[p1.second]){
        avail.push(i);
    }

    while(!pq.empty()){
        pll top = pq.top();
        pq.pop();

        out[avail.front()] = top.second;
        avail.pop();

        for(int i : blocked[top.second]){
            avail.push(i);
        }
    }
    
    for(int a = 1; a <= N; a++){
        if(out[a] == 0){
            cout << p1.second << " ";
        } else {
            cout << out[a] << " ";
        }
    }
}
