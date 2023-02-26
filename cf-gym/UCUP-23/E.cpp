#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool good(int x, int y) { 
    int g = __gcd(x, y);
    set<int> avail = {x, y};
    while (true) {
        int old_size = avail.size();
        for (int i : avail) {
            for (int j : avail) {
                int n = 2 * i - j;
                if (n > 0 && n < 2000)  {
                    avail.insert(n);
                }
            }
        }
        if (avail.size() == old_size) {
            break;
        }
    }
    return avail.count(g);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    int ans = 0;
    for (int x = 1; x <= n; x++) {
        cout << endl;
        string s = to_string(x);
        while (s.size() < 3) {
            s = " " + s;
        }
        cout << s << ": ";
        // cout << x << "/" << n << endl;
        for (int y = 1; y <= n; y++) {
            if (good(x, y) && x < y) {
                // cout << " #";
                cout << x << " " << y << endl;
                ans++;
            } else {
                // cout << " .";
            }
        }
    }
    cout << ans << "\n";
}
