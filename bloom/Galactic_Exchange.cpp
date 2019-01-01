#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXK = 505;

int K;

struct {
    int x, y, z;
    double r;
    string n;
} planet[MAXK];

bool vis[MAXK];
vector<int> adj[MAXK], scc[MAXK], nadj[MAXK];

vector<int> record, cur;

int mat[MAXK][MAXK];
int scc_id[MAXK];

int longest[MAXK];
void solve(int pos){
    if(longest[pos] != 0) return;
    longest[pos] = scc[pos].size();
    for(int i : nadj[pos]){
        solve(i);
        longest[pos] = max(longest[pos], longest[i] + (int)scc[pos].size());
    }
}

vector<string> ans;
void collect(int pos){
    for(int i : scc[pos]){
        ans.push_back(planet[i].n);
    }

    for(int i : nadj[pos]){
        if(longest[i] + (int)scc[pos].size() == longest[pos]){
            collect(i);
            break;
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> K;

    for(int a = 0; a < K; a++){
        string s;
        cin >> s;

        for(char &c : s) if (c == ',') c = ' ';

        stringstream ss(s);
        ss >> planet[a].x >> planet[a].y >> planet[a].z;
        ss >> planet[a].r >> planet[a].n;
    }

    for(int a = 0; a < K; a++){
        for(int b = 0; b < K; b++){
            if(a != b){
                int dx = planet[a].x - planet[b].x;
                int dy = planet[a].y - planet[b].y;
                int dz = planet[a].z - planet[b].z;

                int dist = dx * dx + dy * dy + dz * dz;
                if(dist < planet[a].r * planet[a].r){
                    adj[a].push_back(b);
                    mat[a][b] = true;
                }
            }
        }
    }

    for(int k = 0; k < K; k++){
        for(int a = 0; a < K; a++){
            for(int b = 0; b < K; b++){
                if(mat[a][k] && mat[k][b]){
                    mat[a][b] = true;
                }
            }
        }
    }

    int scc_idx = 0;
    for(int a = 0; a < K; a++){
        if(!vis[a]){
            scc[scc_idx].push_back(a);
            scc_id[a] = scc_idx;
            vis[a] = true;
            for(int b = a + 1; b < K; b++){
                if(mat[a][b] && mat[b][a]){
                    scc[scc_idx].push_back(b);
                    scc_id[b] = scc_idx;
                    vis[b] = true;
                }
            }
            scc_idx++;
        }
    }
    fill(vis, vis + K, false);

    for(int a = 0; a < scc_idx; a++){
        solve(a);
    }

    int best = max_element(longest, longest + K) - longest;
    collect(best);

    sort(allof(ans));
    cout << ans[0];
    for(int a = 1; a < (int)ans.size(); a++){
        cout << "," << ans[a];
    }
}
