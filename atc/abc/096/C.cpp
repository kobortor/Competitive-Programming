#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 55;

int N, M;
char grid[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 1; a <= N; a++){
        cin >> (grid[a] + 1);
    }
    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= M; b++){
            if(grid[a][b] == '#'){
                if(grid[a][b-1] != '#' && grid[a][b+1] != '#' && grid[a-1][b] != '#' && grid[a+1][b] != '#'){
                    cout << "No\n";
                    return 0;
                }
            }
        }
    }
    cout << "Yes\n";
}
