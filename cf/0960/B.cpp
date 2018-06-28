#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N, K1, K2, K3;

int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K1 >> K2;
    K3 = K1 + K2;
    for(int a = 0; a < N; a++){
        cin >> arr[a];
    }
    for(int a = 0; a < N; a++){
        int x;
        cin >> x;
        arr[a] = abs(arr[a] - x);
    }
    while(K3--){
        int *it = max_element(arr, arr + N);
        *it = abs(*it - 1);
    }
    ll ans = 0;
    for(int a = 0; a < N; a++){
        ans += (ll)arr[a] * arr[a];
    }
    cout << ans;
}
