#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5005;

vector<pair<int, long double>> adj[MAXN];

bool cycle[MAXN];
long double best[MAXN];

void dfs(int pos){
    if(cycle[pos]) return;
    cycle[pos] = true;

    for(pair<int, long double> p : adj[pos]){
        dfs(p.first);
    }
}

void testcase(){
    for(int a = 0; a < MAXN; a++){
        cycle[a] = false;
        adj[a].clear();
        best[a] = 1e6;
    }

    int N, M;
    long double D;
    cin >> N >> M >> D;

    best[1] = -log10(D);

    while(M--){
        int A, B;
        long double R;
        cin >> A >> B >> R;
        adj[A].push_back({B, log10(R)});
    }

    for(int x = 1; x <= N; x++){
        for(int a = 1; a <= N; a++){
            for(pair<int, long double> &p : adj[a]){
                if(best[p.first] > best[a] + p.second){
                    best[p.first] = best[a] + p.second;
                }
            }
        }
    }

    for(int a = 1; a <= N; a++){
        for(pair<int, long double> &p : adj[a]){
            if(best[p.first] < 1e5 && best[p.first] > best[a] + p.second){
                dfs(p.first);
            }
        }
    }

    if(cycle[N] || best[N] <= -9){
        cout << "Billionaire!\n";
    } else {
        cout << fixed << setprecision(2) << pow(10, -best[N]) << "\n";
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    const int NTEST = 10;
    for(int a = 1; a <= NTEST; a++){
        testcase();
    }
}
