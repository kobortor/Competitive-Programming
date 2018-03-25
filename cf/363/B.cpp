#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1.5e5 + 5;

int N, K;

int prefix[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    for(int a = 1; a <= N; a++){
        cin >> prefix[a];
        prefix[a] += prefix[a-1];
    }

    pii best = pii(1e9, 0);
    for(int a = 1; a + K - 1 <= N; a++){
        best = min(best, pii(prefix[a + K - 1] - prefix[a - 1], a));
    }
    cout << best.second;
}
