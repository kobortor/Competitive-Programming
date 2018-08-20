#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N;
int nxt[MAXN];
int cost[MAXN];
int incoming[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    for(int a = 1; a <= N; a++){
        cin >> cost[a];
    }

    for(int a = 1; a <= N; a++){
        cin >> nxt[a];
        incoming[nxt[a]]++;
    }

    queue<int> q;
    for(int a = 1; a <= N; a++){
        if(incoming[a] == 0){
            q.push(a);
        }
    }

    while(!q.empty()){
        int fr = q.front();
        q.pop();

        incoming[nxt[fr]]--;
        if(!incoming[nxt[fr]]){
            q.push(nxt[fr]);
        }
    }

    int ans = 0;
    for(int a = 1; a <= N; a++){
        if(incoming[a]){
            int cur = a;
            int best = 1e9;
            do {
                best = min(best, cost[cur]);
                incoming[cur] = 0;
                cur = nxt[cur];
            } while (cur != a);

            ans += best;
        }
    }

    cout << ans;
}
