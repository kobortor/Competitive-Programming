#include "secret.h"
#include <bits/stdc++.h>

const int MAXN = 1005;

int val[MAXN][MAXN];
void Init(int N, int *A){
    memset(val, -1, sizeof val);

    A--;

    for(int a = 1; a <= N; a++){
        val[a][a] = A[a];

        int tmp = A[a];
        for(int b = a - 1; b >= 1; b--){
            if((b & -b) >= (a & -a)){
                break;
            }
            tmp = Secret(A[b], tmp);
            val[b][a] = tmp;
        }

        if(a != N){
            tmp = A[a + 1];
            for(int b = a + 2; b <= N; b++){
                if((b & -b) > (a & -a)){
                    break;
                }
                tmp = Secret(tmp, A[b]);
                val[a + 1][b] = tmp;
            }
        }
    }
}

int Query(int L, int R){
    L++;
    R++;

    if(L == R){
        return val[L][R];
    }

    for(int a = L; a + 1 <= R; a++){
        if(val[L][a] != -1 && val[a + 1][R] != -1){
            return Secret(val[L][a], val[a + 1][R]);
        }
    }
    assert(false);
}
