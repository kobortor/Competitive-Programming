#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll A, B;
ll YB = 0, BB = 0;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	cin >> A >> B;
	ll x, y, z;
	cin >> x >> y >> z;
	YB = 2 * x + y;
	BB = y + 3 * z;
	cout << max(0ll, YB - A) + max(0ll, BB - B);
}
