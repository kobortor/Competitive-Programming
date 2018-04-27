#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    double X, Y, Z;
    cin >> X >> Y >> Z;
    Z /= 60;
    double len = Y - X;

    cout << fixed << setprecision(7) << (len * len - (len - Z) * (len - Z)) / (len * len);
}
