#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        string s;
        cin >> s;

        string a, b;
        for (char c : s) {
            if (c == '4') {
                a += '1';
                b += '3';
            } else {
                a += '0';
                b += c;
            }
        }

        while ((int)a.size() > 1 && a[0] == '0') {
            a = a.substr(1);
        }

        cout << "Case #" << i << ": " << a << " " << b << endl;
    }

}
