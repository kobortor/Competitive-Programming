#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll get_prefix(ll x){
    switch(x & 3){
        case 0: return x;
        case 1: return 1;
        case 2: return x + 1;
        case 3: return 0;
        default: return -1;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    ll xorv = 0;
    while(N--){
        ll x, m;
        cin >> x >> m;
        xorv ^= get_prefix(x + m - 1);
        xorv ^= get_prefix(x - 1);
    }

    if(xorv){
        cout << "tolik";
    } else {
        cout << "bolik";
    }
}
