#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll x, ll y){
    while(x % y){
        x %= y;
        swap(x, y);
    }
    return y;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        ll A, B, C, D;
        cin >> A >> B >> C >> D;
        if(A < B){ // run out first turn
            cout << "No\n";
            continue;
        }

        if(D < B){ //cannot resupply fast enough
            cout << "No\n";
            continue;
        }

        if(C >= B){
            cout << "Yes\n";
            continue;
        }

        ll G = gcd(B, D);
        C++;
        if(A > C){
            ll diff = A - C;
            diff %= G;
            A = C + diff;
        }

        if(A >= B){
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

}
