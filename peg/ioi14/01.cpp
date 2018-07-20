#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N;
int bad[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= N; b++){
            cin >> bad[a][b];
            bad[a][b] ^= 1;
            bad[a][b] += bad[a][b - 1];
        }

        for(int b = 1; b <= N; b++){
            bad[a][b] += bad[a - 1][b];
        }
    }
    
    int ans = 0;
    int cnt = 0;

    for(int a = 1; a <= N; a++){
        int sz = 0;
        for(int b = 1; b <= N; b++){
            while(max(a, b) + sz <= N && bad[a + sz][b + sz] - bad[a + sz][b - 1] - bad[a - 1][b + sz] + bad[a - 1][b - 1] == 0){
                sz++;
            }

            while(max(a, b) + sz - 1 > N || bad[a + sz - 1][b + sz - 1] - bad[a + sz - 1][b - 1] - bad[a - 1][b + sz - 1] + bad[a - 1][b - 1] != 0){
                sz--;
            }

            if(sz > ans){
                ans = sz;
                cnt = 0;
            }

            if(sz == ans){
                cnt++;
            }
        }
    }

    cout << ans * cnt;
}
