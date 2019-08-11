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

    string ans(n, 'o');
    int f1 = 1, f2 = 1;

    while (f2 <= n) {
        ans[f2 - 1] = 'O';

        int tmp = f1 + f2;
        f2 = f1;
        f1 = tmp;
    }

    cout << ans;
}
