#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int R, C;
char grid[55][55];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> R >> C;

    int hr = 0, hc = 0;
    for(int a = 0; a < R; a++){
        cin >> grid[a];
        for(int b = 0; b < C; b++){
            if(grid[a][b] == 'H'){
                hr = a;
                hc = b;
            }
        }
    }

    int up = 0;
    for(int a = 0; a < hr; a++) up += grid[a][hc] == 'C';

    int down = 0;
    for(int a = hr + 1; a < R; a++) down += grid[a][hc] == 'C';

    int lft = 0;
    for(int a = 0; a < hc; a++) lft += grid[hr][a] == 'C';

    int rht = 0;
    for(int a = hc + 1; a < C; a++) rht += grid[hr][a] == 'C';

    cout << max(max(up, down), max(lft, rht));

}
