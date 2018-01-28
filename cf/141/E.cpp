#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/*
The problem statement is wrong
When they refered to simple paths, they also wanted to disallow paths that start and end in the same place
Please refer to this comment thread for details
http://codeforces.com/blog/entry/3571?#comment-72641
*/

const int MAXN = 1005;

int N, M;

int dsu[MAXN];
int cnt[2];
vector<pair<pii, int>> edges;
int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}
vector<int> min_cost(int tp){
    for(int a = 1; a <= N; a++){
        dsu[a] = a;
    }
    int tot = 0;
    for(int i = 0; i < (int)edges.size(); i++){
        if(edges[i].second == tp){
            continue;
        }
        pii p = edges[i].first;
        int fu = find(p.first);
        int fv = find(p.second);
        if(fu != fv){
            tot++;
            dsu[fu] = fv;
        }       
    }

    vector<int> added;
    for(int i = 0; i < (int)edges.size(); i++){
        if(edges[i].second != tp){
            continue;
        }
        pii p = edges[i].first;
        int fu = find(p.first);
        int fv = find(p.second);
        if(fu != fv){
            tot++;
            added.push_back(i);
            dsu[fu] = fv;
        }       
    }
    if(tot != N - 1){
        cout << -1;
        exit(0);
    }
    return added;
}

vector<int> ans;
void solve(int tp){
    for(int i = 0; i < (int)edges.size() && (int)ans.size() < (N - 1) / 2; i++){
        if(edges[i].second != tp){
            continue;
        }
        int fu = find(edges[i].first.first);
        int fv = find(edges[i].first.second);
        if(fu != fv){
            ans.push_back(i);
            dsu[fu] = fv;
        }
    }

    if((int)ans.size() != (N - 1) / 2){
        cout << -1;
        exit(0);
    }
    for(int i = 0; i < (int)edges.size(); i++){
        if(edges[i].second == tp){
            continue;
        }
        int fu = find(edges[i].first.first);
        int fv = find(edges[i].first.second);
        if(fu != fv){
            ans.push_back(i);
            dsu[fu] = fv;
        }
    }
    if((int)ans.size() != (N - 1)){
        cout << -1;
        exit(0);
    }
}


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    if(N % 2 == 0){
        cout << -1;
        return 0;
    }
    for(int a = 0; a < M; a++){
        int u, v;
        char ch;
        cin >> u >> v >> ch;
        edges.push_back({pii(u, v), ch == 'S'});
    }
    vector<int> v0 = min_cost(0);
    vector<int> v1 = min_cost(1);

    int minc0 = v0.size();
    int minc1 = v1.size();
    
    int maxc0 = (N - 1) - minc1;
    int maxc1 = (N - 1) - minc0;

    if(maxc1 < minc0 || maxc0 < minc1){
        cout << -1;
        return 0;
    }
    for(int a = 1; a <= N; a++){
        dsu[a] = a;
    }

    if(minc0 < minc1){
        for(int i : v0){
            int fu = find(edges[i].first.first);
            int fv = find(edges[i].first.second);
            assert(fu != fv);
            dsu[fu] = fv;
        }
        ans = v0;
        solve(0);
    } else {
        for(int i : v1){
            int fu = find(edges[i].first.first);
            int fv = find(edges[i].first.second);
            assert(fu != fv);
            dsu[fu] = fv;
        }
        ans = v1;
        solve(1);
    }
    cout << ans.size() << "\n";
    for(int i : ans){
        cout << i + 1 << " ";
    }
}
