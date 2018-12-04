#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, H;

double W[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> H;

    for(int a = 0; a < N; a++){
        cin >> W[a];
    }

    int ans = 0;
    for(int a = 0; a < N; a++){
        double x;
        cin >> x;

        ans = max(ans, (int)(ceil(W[a] - x / 4) - H));
    }

    cout << ans;
}
