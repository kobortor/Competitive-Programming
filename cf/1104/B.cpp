#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s;
    cin >> s;

    int pairs = 0;
    stack<char> stk;
    for (char c : s) {
        if (stk.empty() || stk.top() != c) {
            stk.push(c);
        } else {
            pairs++;
            stk.pop();
        }
    }

    cout << (pairs % 2 ? "Yes" : "No");
}
