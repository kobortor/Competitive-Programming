#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 305;
const int mod = 10007;

int R, C;
int arr[MAXN][MAXN];
int arow[MAXN], acol[MAXN];

bool modded[MAXN][MAXN * 9];
int dp[MAXN][MAXN * 9];

bool checkline() {
    for(int c = 2; c <= C; c++) if(arr[1][1] != arr[1][c]) return false;
    for(int r = 2; r <= R; r++) if(arr[1][1] != arr[r][1]) return false;

    if(arr[1][1] < 0 || 9 * max(R, C) < arr[1][1]) return false;

    return true;
}

int tot = 0;
vector<vector<vector<int>>> soln;

void solve(){
    if(tot % (R + C - 1) != 0) return;
    
    int ntot = tot / (R + C - 1);

    for(int a = 1; a <= R; a++) if((arow[a] - ntot) % (C - 1) != 0) return;
    for(int a = 1; a <= C; a++) if((acol[a] - ntot) % (R - 1) != 0) return;

    vector<vector<int>> tmp;
    for(int a = 1; a <= R; a++){
        tmp.emplace_back();
        for(int b = 1; b <= C; b++){
            int v = (arow[a] - ntot) / (C - 1) + (acol[b] - ntot) / (R - 1) - arr[a][b];
            if(0 <= v && v <= 9) tmp.back().push_back(v);
            else return;
        }
    }
    soln.push_back(tmp);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    dp[0][0] = 1;
    for(int a = 1; a < MAXN; a++){
        for(int b = 0; b < MAXN * 9; b++){
            for(int c = 0; c <= 9 && b - c >= 0; c++){
                dp[a][b] += dp[a - 1][b - c];
                modded[a][b] |= modded[a - 1][b - c];
            }

            if(dp[a][b] >= mod){
                dp[a][b] %= mod;
                modded[a][b] = true;
            }
        }
    }

    cin >> R >> C;
    for(int r = 1; r <= R; r++) {
        for(int c = 1; c <= C; c++) {
            cin >> arr[r][c];
            tot += arr[r][c];
            arow[r] += arr[r][c];
            acol[c] += arr[r][c];
        }
    }

    if (R == 1 || C == 1) {
        vector<int> soln;
        for(int c = 1; c <= C; c++){
            arr[1][c]++;
            if(checkline()) soln.push_back(arr[1][1]);
            arr[1][c]--;

            arr[1][c]--;
            if(checkline()) soln.push_back(arr[1][1]);
            arr[1][c]++;
        }

        for(int r = 1; r <= R; r++){
            arr[r][1]++;
            if(checkline()) soln.push_back(arr[1][1]);
            arr[r][1]--;

            arr[r][1]--;
            if(checkline()) soln.push_back(arr[1][1]);
            arr[r][1]++;
        }

        sort(allof(soln));
        soln.erase(unique(allof(soln)), soln.end());

        bool hasmod = false;
        int ways = 0;
        for(int i : soln){
            ways += dp[max(R, C)][i];
            hasmod |= modded[max(R, C)][i];
        }

        if(ways >= mod){
            ways %= mod;
            hasmod = true;
        }

        if(ways == 1 && !hasmod){
            for(int r = 1; r <= R; r++){
                for(int c = 1; c <= C; c++){
                    cout << min(9, soln[0]);
                    soln[0] = max(0, soln[0] - 9);
                }
                cout << endl;
            }
        } else {
            cout << ways << " SOLUTIONS";
        }
    } else {
        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                //add
                arr[r][c]++; arow[r]++; acol[c]++; tot++;
                solve();
                tot--; arow[r]--; acol[c]--; arr[r][c]--;

                //subtract
                arr[r][c]--; arow[r]--; acol[c]--; tot--;
                solve();
                tot++; arow[r]++; acol[c]++; arr[r][c]++;
            }
        }
        if((int)soln.size() == 1){
            for(vector<int> v : soln[0]) {
                for(int i : v){
                    cout << i;
                }
                cout << endl;
            }
        } else {
            cout << soln.size() % 10007 << " SOLUTIONS" << endl;
        }
    }
}
