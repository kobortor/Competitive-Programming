#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    double h;
    cin >> n >> h;

    for (int a = 1; a < n; a++) {
        cout << fixed << setprecision(10) << sqrt(a * h * h / n) << "\n";
    }
}
