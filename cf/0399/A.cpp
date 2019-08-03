#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, p, k;
    cin >> n >> p >> k;

    if (1 < p - k) {
        cout << "<< ";
    }
    for (int a = max(1, p - k); a < p; a++) cout << a << " ";
    cout << "(" << p << ") ";
    for (int a = p + 1; a <= min(n, p + k); a++) cout << a << " ";
    if (n > p + k) {
        cout << ">> ";
    }
}
