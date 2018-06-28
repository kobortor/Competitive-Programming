#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 55;

int N, M;
char grid[MAXN][MAXN];
pii start;
string instr;

bool check(vector<pii> dir){
    pii pos = start;
    for(char c : instr){
        pos.first += dir[c - '0'].first;
        pos.second += dir[c - '0'].second;
        
        if (grid[pos.first][pos.second] == 'E') {
            return true;
        }
        if (grid[pos.first][pos.second] == '#') {
            return false;
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N >> M;
    for (int a = 1; a <= N; a++) {
        cin >> (grid[a] + 1);
        grid[a][0] = '#';
        grid[a][M + 1] = '#';
        for (int b = 1; b <= M; b++) {
            if (grid[a][b] == 'S') {
                start = pii(a, b);
            }
        }
    }
    for (int a = 0; a <= M + 1; a++) {
        grid[0][a] = '#';
        grid[N + 1][a] = '#';
    }
    cin >> instr;

    int ans = 0;
    vector<pii> dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    check(dir);
    sort(dir.begin(), dir.end());

    do{
        ans += check(dir);
    } while (next_permutation(dir.begin(), dir.end()));
    cout << ans;
}