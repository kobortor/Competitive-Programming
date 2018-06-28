#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int ans = 0;
    int u, v;
    cin >> u >> v;
    while(min(u, v) > 0 && max(u, v) > 1){
        if(u > v){
            swap(u, v);
        }
        u++;
        v -= 2;
        ans++;
    }
    cout << ans;
}
