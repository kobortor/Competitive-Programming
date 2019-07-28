#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void inf () {
    cout << "Infinite";
    exit(0);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    int ans = 0;

    vector<int> v(n);
    for (int &i : v) cin >> i;

    for (int a = 1; a < n; a++){
        switch(v[a]) {
            case 1:
                if (v[a - 1] == 2) ans += 3;
                if (v[a - 1] == 3) ans += 4;
                break;
            case 2:
                if (v[a - 1] == 1) ans += 3;
                if (v[a - 1] == 3) inf();
                break;
            case 3:
                if (v[a - 1] == 1) ans += 4;
                if (v[a - 1] == 2) inf();
                break;
        }
    }

    for (int a = 2; a < n; a++) {
        if (v[a - 2] == 3 && v[a - 1] == 1 && v[a] == 2) {
            ans--;
        }
    }

    cout << "Finite\n";
    cout << ans;
}
