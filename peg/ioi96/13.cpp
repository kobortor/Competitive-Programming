#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int N;
vector<int> adj[MAXN];
vector<int> nadj[MAXN];

int cnt = 1;
int disc[MAXN], low[MAXN];
int scc[MAXN];
int incoming[MAXN];
bool vis[MAXN];
vector<int> stk;
void tarjan(int pos){
    stk.push_back(pos);
    vis[pos] = true;
    disc[pos] = low[pos] = cnt++;

    for(int i : adj[pos]){
        if(!disc[i]){
            tarjan(i);
            low[pos] = min(low[pos], low[i]);
        } else if (vis[i]){
            low[pos] = min(low[pos], disc[i]);
        }
    }

    if(disc[pos] == low[pos]){
        while(stk.back() != pos){
            scc[stk.back()] = pos;
            vis[stk.back()] = false;
            stk.pop_back();
        }
        scc[stk.back()] = pos;
        vis[stk.back()] = false;
        stk.pop_back();
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        while(true){
            int x;
            cin >> x;
            if(!x){
                break;
            }
            adj[a].push_back(x);
        }
    }

    for(int a = 1; a <= N; a++){
        if(!disc[a]){
            tarjan(a);
        }
    }

    for(int a = 1; a <= N; a++){
        for(int i : adj[a]){
            if(scc[a] != scc[i]){
                nadj[scc[a]].push_back(scc[i]);
                incoming[scc[i]]++;
            }
        }
    }

    int num_begin = 0, num_end = 0;
    int same = 0;
    for(int a = 1; a <= N; a++){
        if(scc[a] == a){
            if(nadj[a].empty() && incoming[a] == 0){
                same++;
            } else if(nadj[a].empty()){
                num_end++;
            } else if(incoming[a] == 0){
                num_begin++;
            }
        }
    }

    cout << num_begin + same << "\n";
    if(num_begin == 0 && num_end == 0 && same == 1){
        cout << "0\n";
    } else {
        cout << max(num_begin, num_end) + same << "\n";
    }
}
