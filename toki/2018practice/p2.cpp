#include "teleport.h"
#include<bits/stdc++.h>
#include <vector>

const int MAXN = 1505;

typedef long long ll;

using namespace std;

//maximum possible value is roughly 2e18
ll best[MAXN][MAXN];
ll tele[MAXN][MAXN];

long long getMaximumPoints(int R, int C, int K,
    vector<vector<int> > T, vector<vector<int> > P) {

    for(int a = 0; a < R; a++){
        for(int b = 0; b < C; b++){
            if(a == 0){
                best[a][b] = P[a][b];
            } else {
                best[a][b] = -2e18;
            }
            if(T[a][b]){
                tele[a][b] = P[a][b];
            } else {
                tele[a][b] = -2e18;
            }
        }
    }

    for(int a = 0; a < R - 1; a++){
        for(int b = 0; b < C; b++){
            best[a + 1][b] = max(best[a + 1][b], best[a][b] + P[a + 1][b]);
            tele[a + 1][b] = max(tele[a + 1][b], tele[a][b] + P[a + 1][b]);
            if(b != 0){
                best[a + 1][b - 1] = max(best[a + 1][b - 1], best[a][b] + P[a + 1][b - 1]);
                tele[a + 1][b - 1] = max(tele[a + 1][b - 1], tele[a][b] + P[a + 1][b - 1]);
            }
            if(b != C - 1){
                best[a + 1][b + 1] = max(best[a + 1][b + 1], best[a][b] + P[a + 1][b + 1]);
                tele[a + 1][b + 1] = max(tele[a + 1][b + 1], tele[a][b] + P[a + 1][b + 1]);
            }
        }
    }

    if(K == 0){
        return *max_element(best[R - 1], best[R - 1] + C);
    } else {
        ll naive = *max_element(best[R - 1], best[R - 1] + C);
        ll initcost = -2e18;
        ll cycle = 0;
        ll last = *max_element(tele[R - 1], tele[R - 1] + C);
        for(int a = 0; a < R; a++){
            for(int b = 0; b < C; b++){
                if(T[a][b]){
                    initcost = max(initcost, best[a][b]);
                    cycle = max(cycle, tele[a][b]);
                }
            }
        }
        return max(naive, initcost + (K - 1) * cycle + last);
    }
}
