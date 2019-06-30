#include<iostream>
#include<utility>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

ll N, K;
ll arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll ans = 0;

    cin >> N >> K;
    for (int a = 1, l = 0; a <= N; a++) {
        cin >> arr[a];
        arr[a] += arr[a - 1];

        while (arr[a] - arr[l + 1] >= K) {
            l++;
        }

        if (arr[a] - arr[l] >= K) {
            ans += l + 1;
        }
    }

    cout << ans;
}
