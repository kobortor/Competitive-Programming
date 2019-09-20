#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;
vector<int> best[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    while (N--) {
        int a;
        cin >> a;
        int cost = 0;

        while (true) {
            best[a].push_back(cost++);
            if (a) a /= 2;
            else break;
        }
    }

    int ans = INT_MAX;
    for (int a = 0; a < MAXN; a++) {
        if ((int)best[a].size() < K) continue;

        sort(allof(best[a]));
        
        int tmp = 0;
        for (int b = 0; b < K; b++) tmp += best[a][b];

        ans = min(ans, tmp);
    }

    cout << ans;
}
