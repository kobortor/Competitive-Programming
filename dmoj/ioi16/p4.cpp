#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;
const int MAXK = 105;

bitset<MAXK> move0[MAXN], move1[MAXN];
bitset<MAXK> vis[MAXN];
bitset<MAXK> backvis[MAXN];
bitset<MAXK> viscol[MAXK];

int blackprefix[MAXN];
bitset<MAXN> canwhite;

string solve_puzzle(string str, int K, int C[]){
    int N = str.size();

    str = "_" + str + "_";

    int N2 = str.size();

    vis[0][0] = true;

    int prvwhite = 0;
    for(int a = 1; a < N2; a++){
        if(str[a] == 'X'){
            continue;
        }

        for(int b = 0; b <= K; b++){
            if(vis[a - 1][b]){
                vis[a][b] = true;
            }
        }

        for(int b = 0; b < K; b++){
            if(prvwhite <= a - C[b] - 1){
                if(vis[a - C[b] - 1][b]){
                    move1[a][b + 1] = true;
                    vis[a][b + 1] = true;
                }
            }
        }

        for(int b = 0; b <= K; b++){
            if(vis[a - 1][b]){
                move0[a][b] = true;
                vis[a][b] = true;
            }
        }

        if(str[a] == '_'){
            prvwhite = a;
        }
    }

    backvis[N2 - 1][K] = true;
    for(int a = N2 - 1; a >= 1; a--){
        for(int b = 0; b <= K; b++){
            if(!backvis[a][b]){
                continue;
            }

            if(move0[a][b]){
                backvis[a - 1][b] = true;
                canwhite[a] = true;
            }
            if(move1[a][b]){
                int prv = a - C[b - 1];
                blackprefix[prv]++;
                blackprefix[a]--;

                backvis[prv - 1][b - 1] = true;

                canwhite[prv - 1] = true;
                canwhite[a] = true;
            }
        }
    }

    string ans;
    ans.reserve(N);
    for(int a = 1; a <= N; a++){
        blackprefix[a] += blackprefix[a - 1];

        if(blackprefix[a] && canwhite[a]){
            ans += '?';
        } else if (blackprefix[a]){
            ans += 'X';
        } else { // if (canwhite[a])
            ans += '_';
        }
    }

    return ans;
}
