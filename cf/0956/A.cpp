#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 55;

int N, M;
char grid[MAXN][MAXN];

int dsu[MAXN * 2];
int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for(int a = 1; a < MAXN * 2; a++){
        dsu[a] = a;
    }

    cin >> N >> M;
    for(int a = 0; a < N; a++){
        cin >> grid[a];
        for(int b = 0; b < M; b++){
            if(grid[a][b] == '#'){
                int fx = find(a);
                int fy = find(N + b);

                dsu[fx] = fy;
            }
        }
    }

    for(int a = 0; a < N; a++){
        for(int b = 0; b < M; b++){
            if(find(a) == find(N + b)){
                if(grid[a][b] != '#'){
                    cout << "No";
                    return 0;
                }
            }
        }
    }
    cout << "Yes";
}
