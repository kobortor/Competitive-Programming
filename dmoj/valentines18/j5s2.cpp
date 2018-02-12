#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 11;

int N, M;
int cost[MAXN];
int offercost[MAXN];
int offer[MAXN][MAXN];
int needed[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 0; a < N; a++){
        cin >> cost[a];
    }
    for(int a = 0; a < M; a++){
        cin >> offercost[a];
        for(int b = 0; b < N; b++){
            cin >> offer[a][b];
        }
    }
    for(int a = 0; a < N; a++){
        cin >> needed[a];
    }

    int best = 0x3f3f3f3f;
    for(int st = 0; st < (1 << 10); st++){
        int tmp = 0;
        for(int b = 0; b < M; b++){
            if(st & (1 << b)){
                tmp += offercost[b];
            }
        }

        for(int a = 0; a < N; a++){
            int rq = needed[a];
            for(int b = 0; b < M; b++){
                if(st & (1 << b)){
                    rq -= offer[b][a];
                }
            }
            if(rq < 0){
                tmp += 99999999;
            } else {
                tmp += rq * cost[a];
            }
        }
        best = min(best, tmp);
    }
    cout << best;
}
