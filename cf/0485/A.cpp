#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int a, m;
    cin >> a >> m;

    for (int i = 0; i < m; i++) {
        a = a * 2 % m;
    }

    cout << (a ? "No" : "Yes");
}
