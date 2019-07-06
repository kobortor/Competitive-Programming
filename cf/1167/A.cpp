#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;

        cin >> n >> s;

        bool good = false;
        for (int a = 0; a + 10 < n; a++) {
            if (s[a] == '8') good = true;
        }

        cout << (good ? "YES\n" : "NO\n");
    }
}
