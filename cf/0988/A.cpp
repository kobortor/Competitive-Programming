#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int N, K;
bool vis[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    vector<int> ans;

    for(int a = 1; a <= N; a++){
        int x;
        cin >> x;
        if(!vis[x]){
            ans.push_back(a);
            vis[x] = true;
        }
    }

    if((int)ans.size() >= K){
        cout << "YES\n";
        for(int a = 0; a < K; a++){
            cout << ans[a] << " ";
        }
    } else {
        cout << "NO\n";
    }
}
