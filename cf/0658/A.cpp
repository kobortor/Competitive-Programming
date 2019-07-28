#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, c;
    cin >> n >> c;

    vector<int> p(n), t(n);
    for (int &i : p) cin >> i;
    for (int &i : t) cin >> i;

    int limak = 0, radewoosh = 0;
    for (int a = 0, tm = 0; a < n; a++) {
        tm += t[a];
        limak += max(0, p[a] - c * tm);
    }
    for (int a = n - 1, tm = 0; a >= 0; a--) {
        tm += t[a];
        radewoosh += max(0, p[a] - c * tm);
    }

    if (limak > radewoosh) {
        cout << "Limak";
    } else if (limak < radewoosh) {
        cout << "Radewoosh";
    } else {
        cout << "Tie";
    }
}
