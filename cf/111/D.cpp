#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;
const int MAXN = 1005;

int N, M, K;

ll qpow(ll x, ll y){
	ll ans = 1;
	while(y){
		if(y & 1){
			ans = ans * x % mod;
		}
		x = x * x % mod;
		y >>= 1;
	}
	return ans;
}

ll fact[MAXN * MAXN];
ll inv[MAXN * MAXN];

ll perm(ll n, ll k){
	return fact[n] * inv[n - k] % mod;
}

ll nck(ll n, ll k){
	return fact[n] * inv[k] % mod * inv[n - k] % mod;
}

ll dp[MAXN][MAXN];
ll powers[MAXN * MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
	fact[0] = 1;
	inv[0] = 1;

	for(int a = 1; a < MAXN * MAXN; a++){
		fact[a] = fact[a - 1] * a % mod;
		inv[a] = qpow(fact[a], mod - 2);
	}

	cin >> N >> M >> K;
	dp[1][1] = 1;
	for(int a = 2; a <= N; a++){
		for(int b = 1; b <= min(K, N); b++){
			dp[a][b] += dp[a - 1][b] * b;
			dp[a][b + 1] += dp[a - 1][b];

			dp[a][b] %= mod;
			dp[a][b + 1] %= mod;
		}
	}

	ll sum = 0;
	if(M == 1){
		for(int a = 1; a <= min(N, K); a++){
			sum += dp[N][a] * perm(K, a);
			sum %= mod;
		}
	} else {
		for(int b = 0; b <= K; b++){
			powers[b] = qpow(b, N * (M - 2));
		}

		//how many unique colors on there
		for(int a = 1; a <= min(K, N); a++){
			//how many are shared
			for(int b = a; 2 * a - b <= K && b >= 0; b--){
				ll to_add = dp[N][a] * dp[N][a] % mod * nck(K, 2 * a - b) % mod; //choose ones we can use
				to_add = to_add * nck(2 * a - b, b) % mod; //choose shared
				to_add = to_add * nck(2 * a - 2 * b, (a - b)) % mod;
				to_add = to_add * fact[a] % mod;
				to_add = to_add * fact[a] % mod;
				to_add = to_add * powers[b] % mod;
				sum += to_add;
				sum %= mod;
			}
		}
	}
	cout << sum;
}
