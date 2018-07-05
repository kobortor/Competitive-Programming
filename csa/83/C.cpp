#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

ll N;

ll arr[MAXN];
ll prv[2 * MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    for(int a = 1; a <= N; a++){
        cin >> arr[a];
    }

    ll ans = 0;
    ll sum = 0;

    fill(prv, prv + 2 * MAXN, 2 * N);

    for(int a = N; a >= 1; a--){
        if(arr[a + 1] >= 0){
            prv[sum + MAXN] = 2 * a;
        }

        if(arr[a] == -1){
            sum += 2;
        } else if (arr[a] == 0){
            sum -= 1;
        } else if (arr[a] == 1){
            prv[sum + MAXN - 1] = 2 * a - 1;
            sum -= 2;
        }

        if(arr[a] == -1){
            ans = max(ans, prv[sum + MAXN] - (2 * a - 2));
        }
    }

    cout << ans / 2.0;
}
