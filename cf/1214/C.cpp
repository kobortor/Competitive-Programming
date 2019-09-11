#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;
int cntL[MAXN];
int cntR[MAXN];

bool good (string s) {
    int n = s.size();
    s = "X" + s;
    for (int a = 1; a <= n; a++) {
        cntL[a] = cntL[a - 1] + (s[a] == '(' ? 1 : -1);
        if (cntL[a] < -1) cntL[a] = -10000;
    }
    for (int a = n; a >= 1; a--) {
        cntR[a] = cntR[a + 1] + (s[a] == '0' ? 1 : -1);
        if (cntR[a] < 0) cntR[a] = -10000;
    }

    for (int a = 1; a <= n; a++) {
        if (cntL[a] == 0 && cntR[a + 1] == 0) return true;
    }

    return false;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    string s;
    cin >> n >> s;

    if (count(allof(s), '(') != count(allof(s), ')')) {
        cout << "No";
    } else {
        bool ans = false;
        ans |= good (s);

        for (char &c : s) c = ('(' + ')') - c;
        reverse(allof(s));

        ans |= good (s);
        cout << (ans ? "Yes" : "No");
    }
}
