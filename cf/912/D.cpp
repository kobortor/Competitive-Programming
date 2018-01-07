#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, M, R, K;
set<pii> vis;

ll get_val(pii p){
	ll lr = max(1ll, p.first - R + 1);
	ll rr = min((ll)p.first, N - R + 1);
	
	ll lc = max(1ll, p.second - R + 1);
	ll rc = min((ll)p.second, M - R + 1);

	if(lr <= rr && lc <= rc){
		return (rr - lr + 1) * (rc - lc + 1);
	} else {
		return 0;
	}
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	cin >> N >> M >> R >> K;
	
	priority_queue<pair<int, pii>> pq;

	int startR = (N + 1) / 2, startC = (M + 1) / 2;
	pii startP = pii(startR, startC);
	pq.push({get_val(startP), startP});
	vis.insert(startP);

	pii moves[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

	ll ans = 0;
	while(!pq.empty() && K > 0){
		pair<int, pii> p = pq.top();
		ans += p.first;
		K--;
		pq.pop();

		for(int a = 0; a < 4; a++){
			pii np = {p.second.first + moves[a].first, p.second.second + moves[a].second};
			if(!vis.count(np)){
				pq.push({get_val(np), np});
				vis.insert(np);
			}
		}
	}
	cout << fixed << setprecision(15) << (double)ans / (N - R + 1) / (M - R + 1);
}
