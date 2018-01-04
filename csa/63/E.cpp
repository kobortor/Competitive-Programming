#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


const int MAXN = 1e5 + 5;

typedef pair<int, int> pii;

int eid = 0;
pii euler[MAXN];
vector<pii> children[MAXN];

vector<int> adj[MAXN];

void euler_tour(int pos, int par){
    euler[pos].first = eid++;
    
    for(int i : adj[pos]){
        if(i != par){
            euler_tour(i, pos);
            
            pii p = euler[i];
            swap(p.first, p.second);
            children[pos].push_back(p);
        }
    }
    
    euler[pos].second = eid - 1;
}

int get_child(int root, int child){
    if(euler[child].first < euler[root].first || euler[root].second < euler[child].first){
        return -1;
    }
    return lower_bound(children[root].begin(), children[root].end(), pii(euler[child].first, -1)) - children[root].begin();
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;
    for(int a = 1; a < N; a++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    euler_tour(1, -1);
    while(Q--){
        int A, B, C;
        cin >> A >> B >> C;
        
        int tpA = get_child(C, A);
        int tpB = get_child(C, B);
        int szC = euler[C].second - euler[C].first + 1;
        
        if (tpA == tpB) {
            cout << 0 << "\n";
        } else if (tpA == -1) {
            int szB = children[C][tpB].first - children[C][tpB].second + 1;
            cout << szC - szB << "\n";
        } else if (tpB == -1) {
            int szA = children[C][tpA].first - children[C][tpA].second + 1;
            cout << szC - szA << "\n";
        } else {
            int szA = children[C][tpA].first - children[C][tpA].second + 1;
            int szB = children[C][tpB].first - children[C][tpB].second + 1;
            cout << (szC - szA - szB) + (N - szC) << "\n";
        }
    }
}