#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int N;
int arr[2][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> arr[0][a];
    }
    for(int a = 1; a <= N; a++){
        cin >> arr[1][a];
    }
    for(int a = 1; a <= N; a++){
        arr[0][a] += arr[0][a - 1];
        arr[1][N - a] += arr[1][N - a + 1];
    }
    int ans = 0;
    for(int a = 1; a <= N; a++){
        ans = max(ans, arr[0][a] + arr[1][a]);
    }
    cout << ans;
}
