#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



void solve(int a, int b, int c) {
    vector<int> ans;

    int k = c / 3;
    int idx = 0;
    ans.push_back(idx);

    if (c % 3 == 0) {
        idx += 2;
        ans.push_back(idx);

        for (int i = 0; i < k; i++) {
            idx += 3;
            ans.push_back(idx);
        }

        idx -= 1;
        ans.push_back(idx);

        for (int i = 0; i < k; i++) {
            idx -= 3;
            ans.push_back(idx);
        }

        idx += 2;
        ans.push_back(idx);

        for (int i = 0; i < k; i++) {
            idx += 3;
            ans.push_back(idx);
        }

        a -= 1;
        b -= 2;
    } else if (c % 3 == 1) {
        for (int i = 0; i < k + 1; i++) {
            idx += 3;
            ans.push_back(idx);
        }

        idx -= 2;
        ans.push_back(idx);

        for (int i = 0; i < k; i++) {
            idx -= 3;
            ans.push_back(idx);
        }

        idx += 1;
        ans.push_back(idx);

        for (int i = 0; i < k; i++) {
            idx += 3;
            ans.push_back(idx);
        }

        idx += 2;
        ans.push_back(idx);

        a -= 1;
        b -= 2;
    } else { // c = 3k + 2
        for (int i = 0; i < k + 1; i++) {
            idx += 3;
            ans.push_back(idx);
        }

        idx -= 1;
        ans.push_back(idx);

        for (int i = 0; i < k; i++) {
            idx -= 3;
            ans.push_back(idx);
        }

        idx -= 1;
        ans.push_back(idx);

        for (int i = 0; i < k + 1; i++) {
            idx += 3;
            ans.push_back(idx);
        }

        a -= 2;
        // b unchanged
    }

    while (a > 1) {
        idx++;
        a--;
        ans.push_back(idx);
    }

    int m = b / 2;
    if (b % 2 == 1) {
        for (int i = 0; i < m + 1; i++) {
            idx += 2;
            ans.push_back(idx);
        }

        idx -= 1;
        ans.push_back(idx);

        for (int i = 0; i < m; i++) {
            idx -= 2;
            ans.push_back(idx);
        }
    } else {
        for (int i = 0; i < m; i++) {
            idx += 2;
            ans.push_back(idx);
        }

        idx += 1;
        ans.push_back(idx);

        for (int i = 0; i < m; i++) {
            idx -= 2;
            ans.push_back(idx);
        }
    }

    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    freopen("jumping.in", "r", stdin);
    freopen("jumping.out", "w", stdout);

    int n;
    cin >> n;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        solve(a, b, c);
    }
}
