#include "assistant.h"
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2018;

static vector<int> genall(int N, int K){
    vector<int> ans;
    for(int a = 0; a < (1 << N); a++){
        int tmp = a;
        int cnt = 0;
        while(tmp){
            cnt++;
            tmp -= tmp & -tmp;
        }
        if(cnt == K){
            ans.push_back(a);
        }
    }
    return ans;
}

struct edge {
    int targ, cap, nxt;
    edge(int t, int c, int n){
        targ = t;
        cap = c;
        nxt = n;
    }
};

static vector<edge> edges;
static int head[MAXN];

static void add_edge(int u, int v){
    edges.push_back({v, 1, head[u]}); head[u] = edges.size() - 1;
    edges.push_back({u, 0, head[v]}); head[v] = edges.size() - 1;
}

static int prv[MAXN];
static bool flow(){
    memset(prv, -1, sizeof prv);
    prv[0] = 0;
    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int fr = q.front();
        q.pop();
        int u = head[fr];
        while(u != -1){
            if(edges[u].cap != 0){
                if(prv[edges[u].targ] == -1){
                    prv[edges[u].targ] = fr;
                    q.push(edges[u].targ);
                }
            }
            u = edges[u].nxt;
        }
    }

    if(prv[MAXN - 1] == -1){
        return false;
    }
    int bk = MAXN - 1;
    while(bk != 0){
        int u = head[bk];
        while(edges[u].targ != prv[bk]){
            u = edges[u].nxt;
        }
        edges[u].cap++;
        edges[u ^ 1].cap--;
        bk = prv[bk];
    }
    return true;
}

static map<int, int> mp;

void initAssistant(int N, int K) {
    memset(head, -1, sizeof head);

    vector<int> v1 = genall(N, K);
    vector<int> v2 = genall(N, K + 1);

    for(int a = 0; a < (int)v1.size(); a++){
        add_edge(0, a + 1);
    }

    for(int a = 0; a < (int)v1.size(); a++){
        for(int b = 0; b < (int)v2.size(); b++){
            int tmp = v1[a] ^ v2[b];
            if((tmp & -tmp) == tmp){
                add_edge(a + 1, v1.size() + b + 1);
            }
        }
    }

    for(int a = 0; a < (int)v2.size(); a++){
        add_edge(v1.size() + a + 1, MAXN - 1);
    }

    int cnt = 0;
    while(flow()){}

    for(int a = 0; a < (int)v1.size(); a++){
        int u = head[a + 1];
        while(u != -1){
            if(edges[u].cap == 0){
                mp[v1[a]] = v2[edges[u].targ - v1.size() - 1];
                break;
            } else {
                u = edges[u].nxt;
            }
        }
    }
}

int giveClue(std::vector<int> cards) {
    int conv = 0;
    for(int i : cards){
        conv |= 1 << (i - 1);
    }

    int tmp = conv ^ mp[conv];
    int ans = 0;
    while(tmp){
        ans++;
        tmp >>= 1;
    }
    return ans;
}
