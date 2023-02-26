#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int tv(char c) {
    return (c - 'a');
}

char sub(char x, char y) {

    int v1 = tv(x);
    int v2 = tv(y);

    return 'a' + ((v1 - v2 + 26) % 26);

}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m; cin >> n >> m;

    string foo; cin >> foo;

    string b; cin >> b;
    string a(m, '?');
    string k(m, '?');

    for (int i = 0; i < n; i++) {

        a[m - 1 - i] = foo[n - i - 1];
        int ind = m - i - 1;
        k[ind] = sub(b[ind], a[ind]);

    }

    for (int i = m - n - 1; i >= 0; i--) {

        a[i] = k[i + n];
        k[i] = sub(b[i], a[i]);

    }

    cout << a << "\n";

    

}
