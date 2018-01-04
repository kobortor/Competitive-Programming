#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;
int arr[2][MAXN];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    for(int a = 0; a < N; a++) {
        cin >> arr[0][a];
    }
    for(int a = 0; a < M; a++) {
        cin >> arr[1][a];
    }
    
    int ans = 0;
    for(int j = 0; j <= M - N; j++) {
        bool good = true;
        for(int i = 0; i < N; i++){
            if(arr[0][i] + arr[1][i + j] != 1){
                good = false;
            }
        }
        ans += good;
    }
    cout << ans;
}