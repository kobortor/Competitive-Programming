#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
int wid[MAXN];
int dist[MAXN * 82];

int id(pii p){
    return p.first * 82 + p.second;
}

vector<pii> get_edges(int r, int c){
    vector<pii> ans;
    if(r != 1){
        ans.push_back(pii(r - 1, min(wid[r - 1], c)));
        if(c == 1){
            ans.push_back(pii(r - 1, wid[r - 1]));
        }
    }

    if(c != 1){
        ans.push_back(pii(r, c - 1));
    }
    if(c != wid[r]){
        ans.push_back(pii(r, c + 1));
    }

    if(r != N){
        ans.push_back(pii(r + 1, min(wid[r + 1], c)));
        if(c == wid[r]){
            ans.push_back(pii(r + 1, 1));
        }
    }
    return move(ans);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> wid[a];
    }

    int rs, cs, rf, cf;
    cin >> rs >> cs >> rf >> cf;

    queue<pii> q;
    q.push(pii(rs, cs));

    memset(dist, 0x3f, sizeof dist);
    dist[id({rs, cs})] = 0;
    
    while(!q.empty()){
        pii fr = q.front();
        q.pop();

        vector<pii> adj = get_edges(fr.first, fr.second);
        for(pii p : adj){
            if(dist[id(fr)] + 1 < dist[id(p)]){
                dist[id(p)] = dist[id(fr)] + 1;
                q.push(p);
            }
        }
    }

    cout << dist[id({rf, cf})];
}
