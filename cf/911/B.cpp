#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, A, B;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	cin >> N >> A >> B;

	int ans = 0;
	for(int a = 1; a < N; a++){
		ans = max(ans, min(A / a, B / (N - a)));
	}
	cout << ans;
}
