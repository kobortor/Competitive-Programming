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

    int ans = 0;
    char cur = 'a';
    for (char c : s) {
        ans += min(26 - abs(c - cur), abs(c - cur));
        cur = c;
    }

    cout << ans;
}
