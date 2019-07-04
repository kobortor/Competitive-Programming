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
    cin >> n;

    for (int a = 1; a < 100; a++) {
        if (a * (a + 1) / 2 == n) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}
