#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M, K;

vector<int> nums[MAXN];

bool not_zero[MAXN];
int incoming[MAXN];
vector<int> adj[MAXN];
int ans[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> K;
    for(int a = 0; a < N; a++){
        for(int b = 0; b < K; b++){
            int x;
            cin >> x;
            nums[a].push_back(x);
        }
        not_zero[nums[a][0]] = true;
    }
    for(int a = 0; a < N - 1; a++) {
        bool solved = false;
        for(int b = 0; b < K; b++) {
            if(nums[a][b] != nums[a + 1][b]){
                adj[nums[a][b]].push_back(nums[a + 1][b]);
                incoming[nums[a + 1][b]]++;
                solved = true;
                break;
            }
        }
        if(!solved){
            return 0;
        }
    }

    queue<int> q;

    for(int a = 0; a < M; a++){
        if(!incoming[a] && !not_zero[a]){
            q.push(a);
        }
    }

    for(int a = 0; a < M; a++){
        if(!incoming[a] && not_zero[a]){
            q.push(a);
        }
    }

    memset(ans, -1, sizeof ans);
    int idx = 0;
    while(!q.empty()){
        int fr = q.front();
        q.pop();
        ans[fr] = idx++;
        for(int i : adj[fr]){
            incoming[i]--;
            if(!incoming[i]){
                q.push(i);
            }
        }
    }
    for(int a = 0; a < M; a++){
        if(ans[a] == -1 || (ans[a] == 0 && not_zero[a])){
            cout << ans[a];
            return 0;
        }
    }

    for(int a = 0; a < M; a++){
        cout << ans[a] << " ";
    }
}
