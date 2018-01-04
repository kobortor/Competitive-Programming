#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

ll N, W, H;
ll words[2 * MAXN]; 
ll prefix[2 * MAXN];
ll jump1[2 * MAXN];
ll nxt[MAXN];
ll seen[MAXN];
ll numone[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
	cin >> N >> W >> H;
	W++;
	for(int a = 1; a <= N; a++){
		cin >> words[a];
		words[a]++;
		words[a + N] = words[a];
	}
	for(int a = 1; a <= 2 * N; a++){
		prefix[a] = words[a] + prefix[a - 1];
	}
	assert(prefix[N] == prefix[2 * N] - prefix[N]);

	ll ans = 0;
	for(int a = 1; a <= N; a++){	
		ll req = (W - words[a]) % prefix[N];
		ll l = a, r = 2 * N;
		jump1[a] = (W - words[a]) / prefix[N];

		while(l <= r){
			ll mid = (l + r) / 2;
			ll sum = prefix[mid] - prefix[a];
			if(sum <= req){
				assert(mid - a <= N);
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		if(a == 1 || l > N + 1){
			jump1[a]++;
		}
	
		if(l > N){
			l -= N;
		}
		nxt[a] = l;
	}

	ll tm = 1, idx = 1, n1 = 0;
	while(H > 0 && !seen[idx]){
		seen[idx] = tm++;
		numone[idx] = n1;

		n1 += jump1[idx];
		ans += jump1[idx];

		H--;
		idx = nxt[idx];
	}
	if(H == 0){
		cout << ans;
		return 0;
	}
	ll cyclelen = tm - seen[idx];
	ll cycleone = n1 - numone[idx];
	ans += H / cyclelen * cycleone;
	H %= cyclelen;

	while(H > 0){	
		ans += jump1[idx];
		idx = nxt[idx];	
		H--;
	}
	cout << ans;
}


