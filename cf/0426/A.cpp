#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, s;
    cin >> n >> s;

    int mx = 0;
    while (n--) {
        int ai;
        cin >> ai;
        mx = max(mx, ai);

        s -= ai;
    }

    if (s + mx >= 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
