#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b){
    while(a % b){
        a %= b;
        swap(a, b);
    }
    return b;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        ll A, B;
        cin >> A >> B;
        ll g = gcd(A, B);
        if(g != (g & -g)){
            cout << "N\n";
        } else {
            cout << "Y\n";
        }
    }
}
