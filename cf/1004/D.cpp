#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

int T;
int cnt[MAXN];

int tmp[MAXN];
bool check(int R, int C, int r, int c){
    if(1 <= r && r <= R && 1 <= c && c <= C){
        //good
    } else {
        return false;
    }

    memset(tmp, 0, sizeof tmp); 
    for(int a = 1; a <= R; a++){
        for(int b = 1; b <= C; b++){
            tmp[abs(r - a) + abs(c - b)]++;
        }
    }

    return equal(cnt, cnt + MAXN, tmp);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int maxv = 0;

    cin >> T;
    for(int a = 1; a <= T; a++){
        int x;
        cin >> x;
        cnt[x]++;

        maxv = max(maxv, x);
    }

    if(cnt[0] != 1){
        cout << -1;
        return 0;
    }

    int first_diff = 1;
    while(cnt[first_diff] == 4 * first_diff) {
        first_diff++;
    }

    for(int row = 1; row <= T; row++){
        if(T % row != 0){
            continue;
        }

        int col = T / row;

        int r = first_diff;
        int c = maxv - (row - r) + 1;

        if(r - 1 > row - r){
            continue;
        }

        if(check(row, col, r, c)){
            cout << row << " " << col << "\n";
            cout << r << " " << c << "\n";
            return 0;
        }
    }

    cout << -1;
}
