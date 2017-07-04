#include<bits/stdc++.h>

#pragma region template code
using namespace std;
template<typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using maxheap = priority_queue<T>;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const int INF = 0x3f3f3f3f;

const int MAXN = 12;
char grid[MAXN][MAXN];
char tmp[MAXN][MAXN];

void flipc(char &c) {
    c = c == '#' ? 'O' : '#';
}

void flip(int r, int c) {
    flipc(tmp[r][c]);

    if(r != 1) {
        flipc(tmp[r - 1][c]);
    }

    if(r != 10) {
        flipc(tmp[r + 1][c]);
    }

    if(c != 1) {
        flipc(tmp[r][c - 1]);
    }

    if(c != 10) {
        flipc(tmp[r][c + 1]);
    }
}

int get_parity(int r, int c){
    int parity = tmp[r][c] == 'O';
    if(r != 1) {
        parity ^= tmp[r - 1][c] == 'O';
    }

    if(r != 10) {
        parity ^= tmp[r + 1][c] == 'O';
    }

    if(c != 1) {
        parity ^= tmp[r][c - 1] == 'O';
    }

    if(c != 10) {
        parity ^= tmp[r][c + 1] == 'O';
    }
    return parity;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif

    while(1) {
        string casename;
        cin >> casename;

        if(casename == "end") {
            break;
        }

        for(int a = 1; a <= 10; a++) {
            for(int b = 1; b <= 10; b++) {
                cin >> grid[a][b];
            }
        }

        int best = 101;
        for(int state = 0; state < (1 << 10); state++) {
            int cost = 0;
            for(int a = 1; a <= 10; a++) {
                for(int b = 1; b <= 10; b++) {
                    tmp[a][b] = grid[a][b];
                }
            }

            for(int a = 0; a < 10; a++) {
                if(state & (1 << a)) {
                    flip(1, a + 1);
                    cost++;
                }
            }

            for(int a = 2; a <= 10; a++) {
                for(int b = 1; b <= 10; b++) {
                    if(tmp[a-1][b] == 'O'){
                        flip(a,b);
                        cost++;
                    }
                }
            }
            for(int a = 1; a <= 10; a++) {
                for(int b = 1; b <= 10; b++) {
                    if(tmp[a][b] == 'O'){
                        cost = 101;
                    }
                }
            }

            best = min(best, cost);
        }
        if(best == 101){
            best = -1;
        }
        cout << casename << " " << best << "\n";
    }
}
