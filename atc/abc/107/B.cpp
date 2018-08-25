#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int N, M;
char grid[MAXN][MAXN];
bool R[MAXN], C[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> N >> M;

    for(int a = 0; a < N; a++){
        cin >> grid[a];
        for(int b = 0; b < M; b++){
            if(grid[a][b] == '#'){
                R[a] = C[b] = true;
            }
        }
    }

    for(int a = 0; a < N; a++){
        if(!R[a]){
            continue;
        }
        for(int b = 0; b < M; b++){
            if(C[b]){
                cout << grid[a][b];
            }
        }
        cout << "\n";
    }
}
