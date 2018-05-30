#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3005;

int N;
int sz[MAXN];
int cost[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> sz[a];
    }
    for(int a = 0; a < N; a++){
        cin >> cost[a];
    }

    int best = 1e9;
    for(int a = 1; a < N - 1; a++){
        int bestleft = 1e9;
        int bestright = 1e9;
        for(int b = 0; b < a; b++){
            if(sz[b] < sz[a]){
                bestleft = min(bestleft, cost[b]);
            }
        }
        for(int b = a + 1; b < N; b++){
            if(sz[a] < sz[b]){
                bestright = min(bestright, cost[b]);
            }
        }

        best = min(best, bestleft + cost[a] + bestright);
    }

    if(best == 1e9){
        cout << -1;
    } else {
        cout << best;
    }
}
