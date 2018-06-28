#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, Q;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> Q;

    vector<pll> flips;

    ll spaces = N - 1;
    ll lvl = 0;
    while(spaces > 0){
        ll flip = 1ll << lvl;
        lvl++;

        ll end = N + spaces;
        ll begin = end - flip;
        flips.push_back({begin, end});

        spaces -= flip;
    }

    reverse(allof(flips));

    while(Q--){
        ll x;
        cin >> x;

        for(pll p : flips){
            //cout << p.first << ", " << p.second << endl;
            if(x <= p.first && (p.first - x) % 2 == 0){
                //cout << x << " -> ";
                x = p.second - (p.first - x) / 2;
                //cout << x << endl;
            } else {
                //cout << x << " stays still\n";
            }
        }

        cout << (x + 1) / 2 << "\n";
    }
}
