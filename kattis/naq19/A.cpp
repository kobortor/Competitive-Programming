#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    char c;

    vector<bool> values;
    for (int a = 0; a < n; a++) {
        cin >> c;
        values.push_back(c == 'T');
    }

    stack<bool> stk;
    while (cin >> c) {
        if ('A' <= c && c <= 'Z') {
            stk.push (values[c - 'A']);
        } else if (c == '*') {
            bool b1 = stk.top(); stk.pop();
            bool b2 = stk.top(); stk.pop();

            stk.push(b1 && b2);
        } else if (c == '+') {
            bool b1 = stk.top(); stk.pop();
            bool b2 = stk.top(); stk.pop();

            stk.push(b1 || b2);
        } else if (c == '-') {
            bool b = stk.top(); stk.pop();

            stk.push (!b);
        }
    }

    cout << (stk.top() ? "T" : "F");
}
