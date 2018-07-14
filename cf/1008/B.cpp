#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    int prvh = 2e9;

    while(N--){
        int u, v;
        cin >> u >> v;
        if(max(u, v) <= prvh){
            prvh = max(u, v);
        } else if (min(u, v) <= prvh){
            prvh = min(u, v);
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
}
