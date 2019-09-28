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
    for (int a = 0; a < n; a += 2) {
        if (s[a] == s[a + 1]) {
            s[a] = 'a' + 'b' - s[a];
            ans++;
        }
    }

    cout << ans << endl << s;
}
