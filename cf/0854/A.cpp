#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int gcd(int a, int b) {
    while (a % b) {
        a %= b;
        swap(a, b);
    }
    return b;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    pii best;
    for (int a = 1; a < n - a; a++) {
        if (gcd(a, n - a) == 1) {
            best = pii(a, n - a);
        }
    }
    
    cout << best.first << " " << best.second << "\n";
}
