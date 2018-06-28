#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
int arr[MAXN];
int minv[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
    }
    for(int a = N, best = -1e9; a >= 1; a--){
        best = max(best, arr[a] - a + 1);
        minv[a] = max(1, best + a);
    }
    for(int a = 1; a <= N; a++){
        minv[a] = max(minv[a], minv[a - 1]);
    }

    ll ans = 0;
    for(int a = 1; a <= N; a++){
        ans += minv[a] - arr[a] - 1;
    }
    cout << ans;
}
