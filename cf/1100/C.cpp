#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, r;
    cin >> n >> r;

    double pi = acos(-1);
    double cosv = 1 - cos(2 * pi / n);

    double a = 2 * cosv - 4;
    double b = 4 * r * cosv;
    double c = 2 * r * r * cosv;

    double k = (-b - sqrt(b*b - 4*a*c)) / (2*a);

    cout << fixed << setprecision(10) << k;
}
