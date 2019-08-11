#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    for (int a = 1; a <= n; a++) {
        if (a % 2 == 1) {
            cout << string(m, '#') << endl;
        } else {
            string s(m, '.');
            if (a % 4 == 2) {
                s.back() = '#';
            } else {
                s[0] = '#';
            }
            cout << s << endl;
        }
    }
}
