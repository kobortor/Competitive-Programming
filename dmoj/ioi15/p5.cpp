#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int pos[MAXN];
bitset<MAXN> vis;

int findSwapPairs(int N, int S[], int M, int X[], int Y[], int P[], int Q[]){
    int lo = 0, hi = N - 1;
    int curmid = 0;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        while(curmid <= mid){
            swap(S[X[curmid]], S[Y[curmid]]);
            curmid++;
        }

        while(curmid > mid){
            curmid--;
            swap(S[X[curmid]], S[Y[curmid]]);
        }

        int cycles = 0;
        for(int a = 0; a < N; a++){
            if(!vis[a]){
                int cur = a;
                while(!vis[cur]){
                    vis[cur] = true;
                    cur = S[cur];
                }
                cycles++;
            }
            vis[a] = false;
        }

        if(N - cycles <= mid){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    if(curmid <= lo){
        swap(S[X[curmid]], S[Y[curmid]]);
        curmid++;
    }

    if(curmid > lo){
        curmid--;
        swap(S[X[curmid]], S[Y[curmid]]);
    }

    int idx = 0;
    for(int a = 0; a < N; a++){
        if(!vis[a]){
            int cur = S[a];
            vis[a] = true;

            while(cur != a){
                vis[cur] = true;
                P[idx] = a;
                Q[idx] = cur;
                idx++;
                cur = S[cur];
            }
        }
    }

    if(idx != lo){
        P[idx] = 0;
        Q[idx] = 0;
        idx++;
    }

    for(int a = 0; a < N; a++){
        pos[S[a]] = a;
    }

    for(int a = lo - 1; a >= 0; a--){
        P[a] = pos[P[a]];
        Q[a] = pos[Q[a]];

        pos[S[X[a]]] = Y[a];
        pos[S[Y[a]]] = X[a];
        swap(S[X[a]], S[Y[a]]);
    }

    return lo;
}
