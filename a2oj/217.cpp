#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll ext_gcd(ll a, ll b, ll &x, ll &y){
    if(a % b == 0){
        x = 0;
        y = 1;
        return b;
    } else {
        ll tmp = ext_gcd(b, a % b, y, x);
        y -= x * (a / b);
        return tmp;
    }
}


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll K;
    cin >> K;
    while(K--){
        ll A, B, X, Y;
        string str;
        cin >> str;
        int slash = str.find("/");

        A = stoll(str.substr(0, slash));
        B = stoll(str.substr(slash + 1));
        ll G = ext_gcd(A, B, Y, X);
        if(G != 1){
            cout << A / G << "/" << B / G << "\n";
        } else {
            X *= -1;

            ll Y1 = (Y % B + B) % B;
            ll X1 = (A * Y1 - 1) / B;

            X *= -1;
            Y *= -1;
            
            ll Y2 = (Y % B + B) % B;
            ll X2 = (A * Y2 + 1) / B;

            if(Y1 > Y2){
                cout << X1 << "/" << Y1 << "\n";
            } else {
                cout << X2 << "/" << Y2 << "\n";
            }
        }
    }
}
