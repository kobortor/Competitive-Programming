#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

ll N, K, M;
ll arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K >> M;
    if(M > K){
        arr[0] = K;
        arr[1] = -K;
        M -= K;
    } else {
        arr[0] = M;
        arr[1] = -M;
        M = 0;
    }
    ll repeats = M / (2 * K * (N - 1));
    M %= 2 * K * (N - 1);

    arr[1] += K * repeats;
    arr[N] -= K * repeats;

    arr[0] += K * repeats;
    arr[N - 1] -= K * repeats;

    for(int a = 1; a < N; a++){
        if(M > K){
            arr[a] += K;
            arr[a + 1] -= K;
            M -= K;
        } else {
            arr[a] += M;
            arr[a + 1] -= M;
            M = 0;
        }
    }

    for(int a = N - 2; a >= 0; a--){
        if(M > K){
            arr[a] += K;
            arr[a + 1] -= K;
            M -= K;
        } else {
            arr[a] += M;
            arr[a + 1] -= M;
            M = 0;
        }
    }
    for(int a = 1; a < N; a++){
        arr[a] += arr[a - 1];
    }

    for(int a = 0; a < N; a++){
        cout << arr[a] << " ";
    }
}
