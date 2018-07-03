#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 4e5 + 5;

int N, D, K;

int dep[MAXN];
int used[MAXN];
vector<pii> edges;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> D >> K;
    
    if(D >= N){
        cout << "NO\n";
        return 0;
    }

    if(D == 1){
        if(N == 1){
            cout << "NO\n";
            return 0;
        } else if(N == 2){
            cout << "YES\n";
            cout << "1 2\n";
            return 0;
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    if(K == 1){
        cout << "NO\n";
        return 0;
    }

    //K > 1, D > 1, N >= D

    queue<int> q;
    q.push(1);
    dep[1] = D / 2;
    int nxt = 2;

    int tmp = 1;

    for(int a = 1; a <= (D + 1) / 2; a++){
        edges.push_back({tmp, nxt});
        used[nxt] = 1;
        used[tmp]++;
        dep[nxt] = (D + 1) / 2 - a;
        q.push(nxt);
        tmp = nxt;
        nxt++;
    }

    tmp = 1;
    for(int a = 1; a <= D / 2; a++){
        edges.push_back({tmp, nxt});
        used[nxt] = 1;
        used[tmp]++;
        dep[nxt] = (D / 2) - a;
        q.push(nxt);
        tmp = nxt;
        nxt++;
    }

    while(!q.empty() && nxt <= N){
        int cur = q.front();
        q.pop();

        if(dep[cur] == 0){
            continue;
        }

        while(nxt <= N && used[cur] < K){
            edges.push_back({cur, nxt});
            dep[nxt] = dep[cur] - 1;
            used[nxt] = 1;
            used[cur]++;
            q.push(nxt);
            nxt++;
        }
    }

    if(nxt <= N){
        cout << "NO\n";
    } else {
        cout << "YES\n";

        for(pii p : edges){
            cout << p.first << " " << p.second << "\n";
        }
    }
}
