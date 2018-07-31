#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int N, M;
char grid[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 1; a <= N; a++){
        cin >> (grid[a] + 1);
    }

    vector<pair<pii, int>> stars;
    for(int a = 1; a <= N; a++) {
        for(int b = 1; b <= M; b++){
            int len = -1;
            while(  grid[a + (len + 1)][b] == '*' && 
                    grid[a - (len + 1)][b] == '*' &&
                    grid[a][b + (len + 1)] == '*' &&
                    grid[a][b - (len + 1)] == '*'){
                len++;
            }

            if(len > 0){
                stars.push_back({{a, b}, len});
            }
        }
    }

    for(pair<pii, int> p : stars){
        for(int a = 0; a <= p.second; a++){
            grid[p.first.first + a][p.first.second] = '.';
            grid[p.first.first - a][p.first.second] = '.';
            grid[p.first.first][p.first.second + a] = '.';
            grid[p.first.first][p.first.second - a] = '.';
        }
    }

    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= M; b++){
            if(grid[a][b] == '*'){
                cout << -1;
                return 0;
            }
        }
    }

    cout << stars.size() << "\n";

    for(pair<pii, int> p : stars){
        cout << p.first.first << " " << p.first.second << " " << p.second << "\n";
    }
}
