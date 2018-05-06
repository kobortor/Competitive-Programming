#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 505;

bool rvis[MAXN];
int best[MAXN];
vector<pii> adj[MAXN];
vector<int> radj[MAXN];

void testcase(){
    for(vector<pii> &vec : adj) vec.clear();
    for(vector<int> &vec : radj) vec.clear();

    int N, M, W;
    cin >> N >> M >> W;

    while(M--){
        int A, B, T;
        cin >> A >> B >> T;
        adj[A].push_back(pii(B, T));
        adj[B].push_back(pii(A, T));

        radj[A].push_back(B);
        radj[B].push_back(A);
    }

    while(W--){
        int A, B, T;
        cin >> A >> B >> T;
        adj[A].push_back(pii(B, -T));

        radj[B].push_back(A);
    }

    memset(rvis, false, sizeof rvis);
    queue<int> q;
    q.push(1);
    rvis[1] = true;
    while(!q.empty()){
        int fr = q.front();
        q.pop();
        for(int i : radj[fr]){
            if(!rvis[i]){
                rvis[i] = true;
                q.push(i);
            }
        }
    }

    memset(best, 0x3f, sizeof best);
    best[1] = 0;
    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= N; b++){
            for(pii p : adj[b]){
                if(best[b] + p.second < best[p.first]){
                    best[p.first] = best[b] + p.second;
                }
            }
        }
    }
    for(int b = 1; b <= N; b++){
        for(pii p : adj[b]){
            if(rvis[p.first] && best[b] + p.second < best[p.first]){
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        testcase();
    }
}
