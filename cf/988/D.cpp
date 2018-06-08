#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
map<ll, ll> mp;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        ll x;
        cin >> x;
        mp[x] = a;
    }

    for(pll p : mp){
        for(ll a = 0; a < 32ll; a++){
            ll diff = 1ll << a;
            if(mp.count(p.first - diff) && mp.count(p.first + diff)){
                cout << "3\n";
                cout << p.first - diff << " " << p.first << " " << p.first + diff << "\n";
                return 0;
            }
        }
    }

    for(pll p : mp){
        for(ll a = 0; a < 32ll; a++){
            ll diff = 1ll << a;
            if(mp.count(p.first + diff)){
                cout << "2\n";
                cout << p.first << " " << p.first + diff << "\n";
                return 0;
            }
        }
    }

    cout << "1\n";
    cout << mp.begin()->first << "\n";
}
