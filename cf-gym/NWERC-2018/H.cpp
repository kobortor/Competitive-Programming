#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, c, b;
    cin >> n >> c >> b;

    string s(n, '0');
    set<int> good;
    for (int i = 0; i < n; i++) {
        good.insert(i);
    }
    good.erase(0);

    while (b--) {
        int x;
        cin >> x;
        good.erase(x - 1);
    }

    if (c % 2 == 1) {
        s[0] = '1';
        good.erase(1);
        c--;
    }

    while (c > 1) {
        int fr = *good.begin();
        good.erase(good.begin());
        if (!good.empty() && *good.begin() == fr + 1) {
            good.erase(good.begin());
        }
        s[fr] = '1';
        c -= 2;
    }
    cout << s << endl;
}
