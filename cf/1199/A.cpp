#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int n, x, y;
int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> x >> y;
    for (int a = 1; a <= n; a++) {
        cin >> arr[a];
    }

    for (int a = 1; a <= n; a++) {
        bool good = true;
        for (int b = max(1, a - x); b <= min(n, a + y); b++) {
            good &= arr[b] >= arr[a];
        }

        if (good) {
            cout << a;
            return 0;
        }
    }
}
