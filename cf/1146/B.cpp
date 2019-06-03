#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string t;
int cnt[26];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> t;

    string tt;
    for (char c : t) {
        if (c != 'a') {
            tt += c;
        }
    }

    if (tt.size() % 2) {
        cout << ":(";
        return 0;
    }

    string t1 = tt.substr(0, tt.size() / 2);
    string t2 = tt.substr(tt.size() / 2, tt.size() / 2);

    if (t1 != t2) {
        cout << ":(";
        return 0;
    }

    if (t.substr(t.size() - t1.size()) == t1) {
        cout << t.substr(0, t.size() - t1.size());
    } else {
        cout << ":(";
    }
}
