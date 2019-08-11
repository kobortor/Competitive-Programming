#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5005;
int f[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    for (int a = 1; a <= n; a++) {
        cin >> f[a];
        if (f[f[f[a]]] == a) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}
