#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;
int ans[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    pii best = {0x3f3f3f3f, -1};

    for(int a = 1; a <= N; a++){
        best = min(best, {a + (N + a - 1) / a, a});
    }

    for(int a = 1; a <= N; a++){
        ans[a] = N - a + 1;
    }

    for(int a = 1; a <= N; a += best.second){
        reverse(ans + a, min(ans + a + best.second, ans + N + 1));
    }

    for(int a = 1; a <= N; a++){
        cout << ans[a] << " ";
    }
}
