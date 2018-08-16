#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M;
int req[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(req, 0x3f, sizeof req);

    cin >> N >> M;

    while(M--){
        int a, b;
        cin >> a >> b;

        req[a] = min(req[a], b);
    }

    int ans = 0;
    for(int a = 1, b = 1e9; a <= N; a++){
        if(b == a){
            ans++;
            b = 1e9;
        }

        b = min(b, req[a]);
    }

    cout << ans;
}
