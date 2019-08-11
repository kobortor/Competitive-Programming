#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            if (a == b) cout << k << " ";
            else cout << 0 << " ";
        }
        cout << "\n";
    }
}
