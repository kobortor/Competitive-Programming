#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;

    if (min(m, k) < n) {
        cout << "No";
    } else {
        cout << "Yes";
    }
}
