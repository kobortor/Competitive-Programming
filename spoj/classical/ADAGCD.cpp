#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e7 + 7;
const ll mod = 1e9 + 7;
const int MAXP = sqrt(MAXN) + 100;

vector<int> primes;
bool sieve[MAXN];

int freq[MAXN];
int cnt[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	for(int a = 2; a < MAXP; a++){
		if(!sieve[a]){
			primes.push_back(a);
			for(int b = 2 * a; b < MAXP; b += a) {
				sieve[b] = true;
			}
		}
	}
	memset(cnt, 0x3f, sizeof cnt);

	int N;
	cin >> N;
	for(int a = 0; a < N; a++){
		map<int, int> tmp;
		int M;
		cin >> M;
		while(M--){
			int x;
			cin >> x;
			for(int i : primes){
				while(x % i == 0){
					tmp[i]++;
					x /= i;
				}
			}
			if(x != 1){
				tmp[x]++;
			}
		}
		for(pii p : tmp){
			freq[p.first]++;
			cnt[p.first] = min(cnt[p.first], p.second);
		}
	}

	ll ans = 1;
	for(int a = 1; a < MAXN; a++){
		if(freq[a] == N){
			while(cnt[a]--){
				ans = ans * a % mod;
			}
		}
	}
	cout << ans;
}
