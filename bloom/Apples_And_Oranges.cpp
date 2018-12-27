#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll extgcd(ll a, ll b, ll &x, ll &y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    } else {
        ll quot = b / a;
        ll g = extgcd(b - quot * a, a, y, x);
        x -= y * quot;
        return g;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll A0, O0, M0, X, Y, Mf;
    cin >> A0 >> O0 >> M0 >> X >> Y >> Mf;

    ll rem = A0 * X + O0 * Y + M0 - Mf;
    ll ax, by;
    ll gcd = extgcd(X, Y, ax, by);

    if(rem < 0 || rem % gcd != 0){
        cout << "Impossible";
    } else {
        ll stepa = Y / gcd;
        ll stepb = X / gcd;
        
        ll minax = ax * ((rem / gcd) % stepa) % stepa;
        ll minby = by * ((rem / gcd) % stepb) % stepb;

        if(minax < 0) minax += stepa;
        if(minby < 0) minby += stepb;

        ll Amax = (rem - minby * Y) / X;
        ll Bmax = (rem - minax * X) / Y;

        if(Amax < 0 || Bmax < 0){
            cout << "Impossible";
        } else {
            cout << Amax << " " << Bmax << endl;
        }
    }
}
