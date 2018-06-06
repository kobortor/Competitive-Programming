#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 205;

int N;
int tp[MAXN];
vector<int> adj[MAXN];
int incoming[MAXN];

int solve(int offset){
    memset(incoming, 0, sizeof incoming);

    for(int a = 1; a <= N; a++){
        for(int i : adj[a]){
            incoming[i]++;
        }
    }

    queue<int> q[3];
    for(int a = 1; a <= N; a++){
        if(incoming[a] == 0){
            q[(tp[a] + offset) % 3].push(a);
        }
    }

    int ans = N;
    int cur = 0;
    while(true){
        while(!q[cur].empty()){
            int fr = q[cur].front();
            q[cur].pop();

            for(int i : adj[fr]){
                incoming[i]--;

                if(!incoming[i]){
                    q[(tp[i] + offset) % 3].push(i);
                }
            }
        }
        if(!q[0].empty() || !q[1].empty() || !q[2].empty()){
            ans++;
            cur = (cur + 1) % 3;
        } else {
            break;
        }
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> tp[a];
        tp[a]--;
    }

    for(int a = 1; a <= N; a++){
        int k;
        cin >> k;
        while(k--){
            int x;
            cin >> x;
            adj[x].push_back(a);
        }
    }

    int ans = 1e9;
    ans = min(ans, solve(0));
    ans = min(ans, solve(1));
    ans = min(ans, solve(2));
    cout << ans;
}
