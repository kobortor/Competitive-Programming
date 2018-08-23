#include "Alicelib.h"
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

void Alice(int N, int M, int A[], int B[]){
    if(N == 1){
        InitG(1, 0);
    } else {
        vector<pii> edges;
        for(int a = 0; a < M; a++){
            edges.push_back({A[a], B[a]});
        }
        for(int a = 0; a < N; a++){
            edges.push_back({a, N});
        }
        for(int a = 1; a <= 10; a++){
            edges.push_back({N, N + a});
        }
        for(int a = 2; a <= 10; a++){
            edges.push_back({N + a, N + 1});
            edges.push_back({N + a, N + 11});
        }
        for(int a = 3; a <= 10; a++){
            edges.push_back({N + a - 1, N + a});
        }
        for(int a = 0; a < N; a++){
            for(int b = 0; b < 10; b++){
                if(a & (1 << b)){
                    edges.push_back({a, N + 1 + b});
                }
            }
        }
        
        InitG(N + 12, edges.size());
        for(int a = 0; a < (int)edges.size(); a++){
            MakeG(a, edges[a].first, edges[a].second);
        }
    }
}
