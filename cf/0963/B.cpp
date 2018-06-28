#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N;

vector<int> adj[MAXN];

vector<pii> solve[MAXN][2];
bool vis[MAXN][2];

void dfs(int pos, int par, int state){
    if(vis[pos][state]){
        return;
    }
    vis[pos][state] = true;

    vector<int> num0, num1, both;

    for(int i : adj[pos]){
        if(i == par){
            continue;
        }
        dfs(i, pos, 0);
        dfs(i, pos, 1);

        if(!solve[i][0].empty() && !solve[i][1].empty()){
            both.push_back(i);
        } else if (!solve[i][0].empty()){
            num0.push_back(i);
        } else if (!solve[i][1].empty()){
            num1.push_back(i);
        } else {
            return;
        }
    }

    vector<pii> &vec = solve[pos][state];
    for(int i : num0){
        vec.push_back(pii(i, 0));
    }
    if(int(!state + num1.size()) % 2 == 1){
        if(both.empty()){
            vec.clear();
            return;
        } else {
            num1.push_back(both.back());
            both.pop_back();
        }
    }
    for(int i : both){
        vec.push_back(pii(i, 0));
    }
    vec.push_back(pii(pos, state));
    for(int i : num1){
        vec.push_back(pii(i, 1));
    }
}

vector<int> soln;
void dfs2(int pos, int par, int state){
/*
    cout << "Visit " << pos << endl;
    cout << "[ ";
    for(pii p : solve[pos][state]){
        cout << p.first << " ";
    }
    cout << "]\n";
*/
    for(pii p : solve[pos][state]){
        if(p.first == par){
            continue;
        }
        if(p == pii(pos, state)){
            soln.push_back(pos);
        } else {
            dfs2(p.first, pos, p.second);
        }
    }
    //cout << "quit\n";
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    for(int a = 1; a <= N; a++){
        int pi;
        cin >> pi;

        if(pi != 0){
            adj[pi].push_back(a);
            adj[a].push_back(pi);
        }
    }

    dfs(1, -1, 1);
    
    if(!solve[1][1].empty()){
        dfs2(1, -1, 1);
    } else {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for(int i : soln){
        cout << i << " ";
    }
}
