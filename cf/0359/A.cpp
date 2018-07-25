#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 55;
int N, M;
int grid[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 0; a < N; a++){
        for(int b = 0; b < M; b++){
            int x;
            cin >> x;
            if(x){
                if(!a || !b || a == N - 1 || b == M - 1){
                    cout << 2;
                    return 0;
                }
            }
        }
    }

    cout << 4;
}
