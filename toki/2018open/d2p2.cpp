#include "tour.h"
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 605;

struct edge {
    int targ, cap, nxt;
    edge(int t, int c, int n) {
        targ = t;
        cap = c;
        nxt = n;
    }
};
vector<edge> edges;

int head[MAXN];

void add_edge(int u, int v){
    edges.push_back({v, 1, head[u]}); head[u] = edges.size() - 1;
    edges.push_back({u, 0, head[v]}); head[v] = edges.size() - 1;
}

int prv[MAXN];
bool flow(){
    memset(prv, -1, sizeof prv);
    prv[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int fr = q.front();
        q.pop();
        
        int id = head[fr];
        while(id != -1){
            if(edges[id].cap && prv[edges[id].targ] == -1){
                prv[edges[id].targ] = fr;
                q.push(edges[id].targ);
            }
            id = edges[id].nxt;
        }
    }

    if(prv[MAXN - 1] == -1) return false;

    int cur = MAXN - 1;
    while(cur != 0){
        int id = head[cur];
        while(id != -1){
            if(edges[id].targ == prv[cur]){
                edges[id].cap++;
                edges[id ^ 1].cap--;
                cur = prv[cur];
            }
            id = edges[id].nxt;
        }
    }
    return true;
}

int getShortestTour(int N, std::vector<std::string> S) {
    memset(head, -1, sizeof head);

    for(int a = 0; a < N; a++){
        add_edge(0, a + 1);
        add_edge(N + a + 1, MAXN - 1);
        for(int b = 0; b < N; b++){
            if(S[a][b] == '.'){
                add_edge(a + 1, N + b + 1);
            }
        }
    }

    int whites = 0;
    while(flow()){
        whites++;
    }
    return 2 * (N - 1) - min(N - 1, whites);
}
