#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;
const int NCASES = 10;

vector<int> adj[MAXN];
int best[MAXN];

void testcase(){
    memset(best, 0x3f, sizeof best);

    int H, V;
    cin >> H >> V;
    int Sh, Sv;
    cin >> Sh >> Sv;
    int Fh, Fv;
    cin >> Fh >> Fv;

    int Si = Sh * V + Sv;
    int Fi = Fh * V + Fv;

    best[Si] = 0;

    int N;
    cin >> N;
    for(int a = 0; a < N; a++){
        int Th, Tv, Uh, Uv;
        cin >> Th >> Tv >> Uh >> Uv;
        int Ti = Th * V + Tv;
        int Ui = Uh * V + Uv;

        adj[Ti].push_back(Ui);
        adj[Ui].push_back(Ti);
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, Si));

    while(!pq.empty()){
        pii top = pq.top();
        pq.pop();

        for(int i : adj[top.second]){
            if(top.first < best[i]){
                best[i] = top.first;
                pq.push(pii(best[i], i));
            }
        }
        if(top.second % V != 0){
            int np = top.second - 1;
            if(top.first + 1 < best[np]){
                best[np] = top.first + 1;
                pq.push(pii(best[np], np));
            }
        }
        if(top.second % V != V - 1){
            int np = top.second + 1;
            if(top.first + 1 < best[np]){
                best[np] = top.first + 1;
                pq.push(pii(best[np], np));
            }
        }
        if(top.second >= V){
            int np = top.second - V;
            if(top.first + 1 < best[np]){
                best[np] = top.first + 1;
                pq.push(pii(best[np], np));
            }
        }
        if(top.second + V < V * H){
            int np = top.second + V;
            if(top.first + 1 < best[np]){
                best[np] = top.first + 1;
                pq.push(pii(best[np], np));
            }
        }
    }

    cout << best[Fi] << "\n";

    for(int a = 0; a < H * V; a++){
        adj[a].clear();
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for(int a = 0; a < NCASES; a++){
        testcase();
    }
}
