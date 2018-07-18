#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N;
ll arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
        arr[a] += arr[a - 1];
    }

    ll ans = 0;
    for(int a = 0, b = N + 1; a <= N; a++){
        while(arr[a] > arr[N] - arr[b - 1]){
            b--;
        }

        if(a < b && arr[a] == arr[N] - arr[b - 1]){
            ans = max(ans, arr[a]);
        }
    }

    cout << ans;
}
