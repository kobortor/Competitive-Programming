#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N, M, K;

int prefix[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> K;
    while(M--){
        int x;
        cin >> x;
        prefix[max(1, x - K)]++;
        prefix[min(x + K + 1, MAXN - 1)]--;
    }

    int lim = -1;
    int ans = 0;
    int cnt = 0;

    for(int a = 1; a <= N; a++){
        cnt += prefix[a];
        if(!cnt && lim < a){
            lim = a + 2 * K;
            ans++;
        }
    }
    cout << ans;
}
