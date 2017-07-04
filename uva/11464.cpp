#include<bits/stdc++.h>

#pragma region template code
using namespace std;
template<typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using maxheap = priority_queue<T>;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const int INF = 0x3f3f3f3f;

const int MAXN = 16;
int grid[MAXN][MAXN];
int tmp[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        int N;
        cin >> N;
        for(int a=0; a<N; a++){
            for(int b=0; b<N; b++){
                cin >> grid[a][b];
            }
        }

        int best = INF;

        for(int state = 0; state < (1<<N); state++){
            bool possible = true;
            for(int a=0; a<N; a++){
                for(int b=0; b<N; b++){
                    tmp[a][b] = grid[a][b];
                }
            }

            for(int a=0; a<N; a++){
                if(state & (1<<a)){
                    tmp[0][a] = 1;
                }
            }
            for(int a=1; a<N && possible; a++){
                for(int b=0; b<N && possible; b++){
                    int parity = tmp[a][b];
                    if(a - 1 != 0){
                        parity ^= tmp[a-2][b];
                    }
                    if(b != 0){
                        parity ^= tmp[a-1][b-1];
                    }
                    if(b != N - 1){
                        parity ^= tmp[a-1][b+1];
                    }

                    if(parity == 1){
                        if(tmp[a][b] == 0){
                            tmp[a][b] = 1;
                        }else{
                            possible = false;
                        }
                    }
                }
            }

            for(int a=0; a<N; a++){
                int parity = 0;
                if(N != 1){
                    parity ^= tmp[N - 2][a];
                }
                if(a != 0){
                    parity ^= tmp[N-1][a-1];
                }
                if(a != N - 1){
                    parity ^= tmp[N-1][a+1];
                }
                if(parity){
                    possible = false;
                }
            }

            if(possible){
                int cost = 0;
                for(int a=0; a<N; a++){
                    for(int b=0; b<N; b++){
                        if(tmp[a][b] && !grid[a][b]){
                            cost++;
                        }
                    }
                }
                best = min(best, cost);
            }
        }
        cout << "Case " << test << ": ";
        if(best == INF){
            cout << -1 << "\n";
        }else{
            cout << best << "\n";
        }
    }
}
