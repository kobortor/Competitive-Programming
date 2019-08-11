#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (int a = 0; a + 1 < n; a++) {
        ans += s[a] == s[a + 1];
    }

    cout << ans;
}
