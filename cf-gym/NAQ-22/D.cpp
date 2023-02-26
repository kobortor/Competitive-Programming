#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, m; cin >> n >> m;

    vector<int> a(n + 1);
    iota(a.begin(), a.end(), 0);

    while (m--) {
    	int x; cin >> x;
    	swap(a[x], a[x + 1]);
    }

    for (int i = 1; i <= n; i++)
    	cout << a[i] << "\n";

}
