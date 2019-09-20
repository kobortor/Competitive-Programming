#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, k;

// (p . s)[i] = s[p[i]]
// (p . q . s)[i] = s[q[p[i]]]
vector<int> compose (vector<int> p, vector<int> q) {
    vector<int> ans;
    for (int a = 0; a < n; a++) {
        ans.push_back(q[p[a]]);
    }

    return ans;
}

vector<int> inv (vector<int> p) {
    vector<int> ans(n);
    for (int a = 0; a < n; a++) {
        ans[p[a]] = a;
    }

    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> k;

    vector<int> p(n), q(n);

    for (int &i : p) {
        cin >> i;
        i--;
    }
    for (int &i : q) {
        cin >> i;
        i--;
    }

    vector<int> A = compose (q, inv(p));

    int cnt = 0;

    // g satisfies Ord(g) and Ord(A . g)
    // g = p . s
    // A = q . inv(p)
    string g;
    for (int a = 0, rhs = 0; a < n; a++) {
        g += char('a' + min(25, cnt));
        rhs = max(rhs, A[a]);
        if (a == rhs) {
            cnt++;
        }
    }

    if (cnt < k) {
        cout << "NO";
        return 0;
    }

    vector<int> p_inv = inv(p);
    cout << "YES\n";
    for (int a = 0; a < n; a++) {
        cout << g[p_inv[a]];
    }
}
