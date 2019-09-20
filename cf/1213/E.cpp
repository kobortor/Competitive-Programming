#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool good (string chk, string s, string t) {
    return chk.find(s) == string::npos && chk.find(t) == string::npos;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    string s, t;
    cin >> n >> s >> t;

    cout << "YES" << endl;
    if (s[0] == s[1] || t[0] == t[1]) {
        if (good("abca", s, t)) {
            for (int a = 0; a < n; a++) cout << "abc";
        } else {
            for (int a = 0; a < n; a++) cout << "cba";
        }
    } else {
        string perm = "abc";
        do {
            if (perm.find(s) == string::npos && perm.find(t) == string::npos) {
                for (int a = 0; a < n; a++) cout << perm[0];
                for (int a = 0; a < n; a++) cout << perm[1];
                for (int a = 0; a < n; a++) cout << perm[2];
                return 0;
            }
        } while (next_permutation(perm.begin(), perm.end()));
    }
}
