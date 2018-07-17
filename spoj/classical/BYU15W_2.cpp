#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 10;

int N;

int mat[MAXN][MAXN];

bool taken[MAXN];
int ans;

void solve(int idx, int sum){
    if(idx == N){
        ans = min(ans, abs(sum));
        return;
    }

    for(int a = 0; a < N; a++){
        if(!taken[a]){
            taken[a] = true;

            solve(idx + 1, sum + mat[idx][a]);
            solve(idx + 1, sum - mat[idx][a]);

            taken[a] = false;
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        ans = 1e9;

        cin >> N;
        for(int a = 0; a < N; a++){
            for(int b = 0; b < N; b++){
                cin >> mat[a][b];
            }
        }
        solve(0, 0);

        cout << ans << "\n";
    }
}
