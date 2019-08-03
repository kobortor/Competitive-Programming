#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int cnt[128];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s;
    cin >> s;
    for (char c : s) cnt[(int)c]++;

    int ans = 999999;
    ans = min(ans, cnt[(int)'i']);
    ans = min(ans, cnt[(int)'t']);
    ans = min(ans, (cnt[(int)'n'] - 1) / 2);
    ans = min(ans, cnt[(int)'e'] / 3);

    cout << max(ans, 0);
}
