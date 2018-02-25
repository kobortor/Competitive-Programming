#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, Q;
int prefix[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> Q;
    while(Q--){
        int a, b;
        cin >> a >> b;
        prefix[a + 1]++;
        prefix[b + 1]--;
    }

    int ans = 0;
    for(int a = 1; a <= N; a++){
        prefix[a] += prefix[a - 1];
        if(prefix[a]){
            ans++;
        }
    }
    cout << N - ans << " " << ans;

}
