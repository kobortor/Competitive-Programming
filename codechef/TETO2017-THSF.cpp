#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100;
const int MAXM = 10;

int src[MAXN][MAXM];
int best[MAXN][MAXM];
int cost[MAXN][MAXM];
bool cand[MAXN][MAXM];

int N, M;

void test(){
    cin >> N >> M;
    for(int b = 0; b < N; b++){
        for(int a = 0; a < M; a++){
            cin >> cost[a][b];
        }
    }
    memset(best, 0x3f, sizeof(best));

    for(int a = 0; a < N; a++){
        best[M - 1][a] = cost[M - 1][a];
    }
    for(int a = M - 2; a >= 0; a--){
        for(int b = 0; b < N; b++){
            best[a][b] = min(best[a+1][b], min(best[a+1][(b+1)%N], best[a+1][(b+N-1)%N])) + cost[a][b];
        }
    }

    memset(cand, 0, sizeof(cand));
    int minv = *min_element(best[0], best[0] + N);
    for(int a = 0; a < N; a++){
        if(best[0][a] == minv){
            cand[0][a] = true;
        }
    }
    for(int a = 0; a < M - 1; a++){
        int minv = 1e9, minc = 1e9;
        for(int b = 0; b < N; b++){
            if(cand[a][b]){
                minv = min(minv, best[a][b]);
            }
        }
        for(int b = 0; b < N; b++){
            if(cand[a][b] && best[a][b] == minv){
                minc = min(minc, cost[a][b]);
            }
        }
        for(int b = 0; b < N; b++){
            if(cand[a][b] && best[a][b] == minv && cost[a][b] == minc){
                if(best[a + 1][b] + cost[a][b] == best[a][b]){
                    // printf("%i, %i extend to %i\n", a, b, b);
                    cand[a + 1][b] = true;
                    src[a + 1][b] = b;
                }

                if(best[a + 1][(b + 1) % N] + cost[a][b] == best[a][b]){
                    //printf("%i, %i extend to %i\n", a, b, (b + 1) % N);
                    cand[a + 1][(b + 1) % N] = true;
                    src[a + 1][(b + 1) % N] = b;
                }

                if(best[a + 1][(b + N - 1) % N] + cost[a][b] == best[a][b]){
                    //printf("%i, %i extend to %i\n", a, b, (b + N - 1) % N);
                    cand[a + 1][(b + N - 1) % N] = true;
                    src[a + 1][(b + N - 1) % N] = b;
                }
            }
        }
    }
    int idx = -1;
    for(int a = 0; a < N; a++){
        if(cand[M - 1][a]){
            idx = a;
        }
    }
    string str;
    str += to_string(idx + 1);
    for(int a = M - 1; a >= 1; a--){
        idx = src[a][idx];
        str += to_string(idx + 1);
    }
    reverse(str.begin(), str.end());
    cout << str << "\n";
}

int main(){
    //cin.tie(0);
    //cin.sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        test();
    }
}