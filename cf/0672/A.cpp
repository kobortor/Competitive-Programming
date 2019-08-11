#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int pow10 (int x) {
    return x == 0 ? 1 : 10 * pow10(x - 1);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    n--;

    int ndig = 1;
    while (9 * pow10(ndig - 1) * ndig <= n) {
        n -= 9 * pow10(ndig - 1) * ndig;
        ndig++;
    }

    int val = pow10(ndig - 1) + n / ndig;
    cout << to_string(val)[n % ndig];
}
