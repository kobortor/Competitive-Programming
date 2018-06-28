#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, K;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	cin >> N >> K;

	ll ans = 1;
	if(K >= 4){
		ans += N * (N - 1) * (N - 2) * (N - 3) / 4;
		ans += N * (N - 1) * (N - 2) * (N - 3) / 24 * 3;
	}
	if(K >= 3){
		ans += N * (N - 1) * (N - 2) / 3;
	}
	if(K >= 2){
		ans += N * (N - 1) / 2;
	}
	cout << ans;
}
