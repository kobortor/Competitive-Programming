#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 305;

bool win[MAXN][MAXN][MAXN];
int dp1[MAXN][MAXN];
int dp2[MAXN][MAXN];

int val[3];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> val[a];
    }

    if(N == 1){
        cout << (val[0] ? "BitLGM" : "BitAryo");
        return 0;
    }

    if(N == 2){
        if(val[0] > val[1]){
            swap(val[0], val[1]);
        }
        
        for(int a = 0; a < MAXN; a++){
            for(int b = a; b < MAXN; b++){
                for(int c = 1; c <= a; c++){
                    dp1[a][b] |= !dp1[a - c][b];
                }
                for(int c = 1; c <= b; c++){
                    if(c <= a){
                        dp1[a][b] |= !dp1[a - c][b - c];
                    }

                    dp1[a][b] |= !dp1[min(a, b - c)][max(a, b - c)];
                }
            }
        }
        if(dp1[val[0]][val[1]]){
            cout << "BitLGM";
        } else {
            cout << "BitAryo";
        }
        return 0;
    }

    sort(val, val + 3);

    memset(dp1, 0x3f, sizeof dp1);
    memset(dp2, 0x3f, sizeof dp2);

    dp1[0][0] = 0;
    dp2[0][0] = 0;

    for(int a = 0; a < MAXN; a++){
        for(int b = a; b < MAXN; b++){
            for(int c = b; c < MAXN; c++){
                win[a][b][c] |= dp1[a][b] < c;
                win[a][b][c] |= dp1[a][c] < b;
                win[a][b][c] |= dp1[b][c] < a;

                if(a != 0){
                    win[a][b][c] |= dp2[b - a][c - a] < a;
                }

                if(!win[a][b][c]){
                    dp1[a][b] = min(dp1[a][b], c);
                    dp1[a][c] = min(dp1[a][c], b);
                    dp1[b][c] = min(dp1[b][c], a);

                    dp2[b - a][c - a] = min(dp2[b - a][c - a], a);
                }
            }
        }
    }

    if(win[val[0]][val[1]][val[2]]){
        cout << "BitLGM";
    } else {
        cout << "BitAryo";
    }
}
