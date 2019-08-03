#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;
bool got[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    int targ = n;
    for (int a = 1; a <= n; a++) {
        int x;
        cin >> x;
        got[x] = true;

        while (got[targ]) {
            cout << targ << " ";
            targ--;
        }
        cout << "\n";
    }
}
