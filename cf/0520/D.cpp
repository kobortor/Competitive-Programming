#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 9;
const int MAXM = 1e5 + 5;

int M;
map<pii, int> cubes;
set<int> avail;
pii cube[MAXM];
vector<int> adj[MAXM];
vector<int> radj[MAXM];
int dep[MAXM];
bool used[MAXM];

void check_dep(int pos){
    int below = 0;
    for(int i : adj[pos]){
        below += !used[i];
    }

    if(below == 1){
        for(int i : adj[pos]){
            dep[i]++;
            avail.erase(i);
        }
    }
}

void remove(int pos){
    used[pos] = true;
    for(int i : radj[pos]){
        if(!used[i]){
            check_dep(i);
        }
    }

    int blocked = 0;
    for(int i : adj[pos]){
        blocked += !used[i];
    }

    if(blocked == 1){
        for(int i : adj[pos]){
            if(!used[i] && ! --dep[i]){
                avail.insert(i);
            }
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> M;
    for(int a = 0; a < M; a++){
        cin >> cube[a].first >> cube[a].second;
        cubes[cube[a]] = a;
        avail.insert(a);
    }

    for(int a = 0; a < M; a++){
        int x, y;
        tie(x, y) = cube[a];
        if(cubes.count(pii(x - 1, y - 1))){
            adj[a].push_back(cubes[pii(x - 1, y - 1)]);
        }
        if(cubes.count(pii(x, y - 1))){
            adj[a].push_back(cubes[pii(x, y - 1)]);
        }
        if(cubes.count(pii(x + 1, y - 1))){
            adj[a].push_back(cubes[pii(x + 1, y - 1)]);
        }
    }

    for(int a = 0; a < M; a++){
        for(int i : adj[a]){
            radj[i].push_back(a);
        }
    }

    for(int a = 0; a < M; a++){
        check_dep(a);
    }

    ll ans = 0;
    for(int step = 0; step < M; step++){
        assert(!avail.empty());
        if(step % 2 == 0){
            int val = *prev(avail.end());
            ans = (ans * M + val) % mod;
            remove(val);
            avail.erase(val);
        } else {
            int val = *avail.begin();
            ans = (ans * M + val) % mod;
            remove(val);
            avail.erase(val);
        }
    }

    cout << ans << "\n";
}
