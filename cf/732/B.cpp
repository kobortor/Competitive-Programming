#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 505;

int N, K;

int ans = 0;
int walk[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;

    walk[0] = K;
    for(int a = 1; a <= N; a++){
        cin >> walk[a];
        while(walk[a-1] + walk[a] < K){
            ans++;
            walk[a]++;
        }
    }
    cout << ans << "\n";

    for(int a = 1; a <= N; a++){
        cout << walk[a] << " ";
    }
}
