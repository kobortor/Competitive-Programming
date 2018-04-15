#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll X, D;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    vector<ll> vec;

    cin >> X >> D;

    ll start = 2;

    while(X){
        ll before = 0;
        while(X >= (1 << before)){
            X -= 1 << before;
            vec.push_back(start);
            before++;
            if(vec.size() > 10000){
                cout << -1;
                return 0;
            }
        }
        start += 2 * D;
    }
    cout << vec.size() << "\n";
    for(ll i : vec){
        cout << i << " ";
    }
}
