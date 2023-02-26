#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int ans[MAXN];

int solve(int n) {
    if (ans[n] != -1) return ans[n];

    ans[n] = 1e9;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ans[n] = min(ans[n], solve(i) + solve(n / i));
        }
    }

    for (int l = 1; l + 1 <= n; l++) {
        ans[n] = min(ans[n], solve(l) + solve(n - l));
    }

    string s = to_string(n);
    for (int i = 1; i < (int)s.size(); i++) {
        string l = s.substr(0, i);
        string r = s.substr(i, string::npos);
        if (r[0] != '0') {
            ans[n] = min(ans[n], solve(stoi(l)) + solve(stoi(r)));
        }
    }
    return ans[n];
}

string encode(vector<int> v) {
    string s;
    for (int i = 0; i < v.size(); i += 2) {
        int x = v[i] + 7;
        int y = v[i + 1] + 7;
        int z = '#' + x * 9 + y;
        if (z >= '\\') z++;
        s += char(z);
    }
    return s;
}

vector<int> decode(string s) {
    int cur = 0;
    vector<int> v;
    for (char c : s) {
        if (c >= '\\') {
            c--;
        }
        int x = (c - '#');
        cur += x / 9 - 7;
        v.push_back(cur);
        cur += x % 9 - 7;
        v.push_back(cur);
    }
    return v;
}

int main() {
    memset(ans, -1, sizeof ans);
    ans[1] = 1;

    vector<int> diffs;

    int prv = 0;
    for (int i = 1; i <= 100000; i++) {
        int cur = solve(i);
        cout << i << " gets " << cur << endl;

        diffs.push_back(cur - prv);

        prv = cur;
    }
    cout << encode(diffs) << endl;
}
