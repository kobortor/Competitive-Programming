#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N, M;
int arr[MAXN][MAXN];
int ver[MAXN][MAXN];
int hor[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= M; b++){
            cin >> arr[a][b];
            ver[a][b] = arr[a][b];
            hor[a][b] = arr[a][b];

            ver[a][b] += ver[a - 1][b];
            hor[a][b] += hor[a][b - 1];
        }
    }

    int ans = 0;
    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= M; b++){
            if(!arr[a][b]){
                ans += ver[a][b] > 0;
                ans += hor[a][b] > 0;

                ans += ver[N][b] > ver[a][b];
                ans += hor[a][M] > hor[a][b];
            }
        }
    }

    cout << ans;
}
