#include "quality.h"
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3005;

int R, C, H, W;

int grid[MAXN][MAXN];

bool good(){
    for(int a = 1; a <= R; a++){
        for(int b = 1; b <= C; b++){
            grid[a][b] += grid[a][b - 1];
        }
        for(int b = 1; b <= C; b++){
            grid[a][b] += grid[a - 1][b];
        }
    }

    for(int a = H; a <= R; a++){
        for(int b = W; b <= C; b++){
            if(grid[a][b] - grid[a - H][b] - grid[a][b - W] + grid[a - H][b - W] <= 0){
                return true;
            }
        }
    }

    return false;
}

int rectangle(int _R, int _C, int _H, int _W, int Q[3001][3001]) {
    R = _R;
    C = _C;
    H = _H;
    W = _W;

    int lo = 1, hi = R * C;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        for(int a = 1; a <= R; a++){
            for(int b = 1; b <= C; b++){
                if(Q[a - 1][b - 1] < mid){
                    grid[a][b] = -1;
                } else if (Q[a - 1][b - 1] > mid){
                    grid[a][b] = 1;
                } else {
                    grid[a][b] = 0;
                }
            }
        }
        if(good()){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return lo;
}
