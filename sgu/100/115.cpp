#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    if (m > 12 || n > month[m]) {
        cout << "Impossible";
        return 0;
    }

    int day = 1;
    for (int a = 1; a < m; a++) {
        day += month[a];
    }
    day += n - 1;

    if (day % 7 == 0) cout << 7;
    else cout << day % 7;
}
