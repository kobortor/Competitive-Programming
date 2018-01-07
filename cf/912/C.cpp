#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

ll N, M;

ll bounty, inc, dmg;
ll max_health[MAXN];
ll start_health[MAXN];
ll regen[MAXN];

struct eve {
	ll T, H;
	bool operator<(const eve &e) const {
		return T < e.T;
	}
};
vector<eve> events[MAXN];

vector<pll> good_ranges;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	cin >> N >> M;
	cin >> bounty >> inc >> dmg;

	for(int a = 1; a <= N; a++){
		cin >> max_health[a];
		cin >> start_health[a];
		cin >> regen[a];
		if(max_health[a] <= dmg && inc != 0){
			cout << -1;
			return 0;
		}
	}
	for(int a = 1; a <= M; a++){
		int targ;
		eve e;
		cin >> e.T;
		cin >> targ;
		cin >> e.H;
		events[targ].push_back(e);
	}

	for(int a = 1; a <= N; a++){
		sort(events[a].begin(), events[a].end());
		ll tm = 0, hl = start_health[a];
		for(eve e : events[a]){
			if(hl <= dmg){
				ll start_better = (regen[a] == 0 ? e.T : tm + 1 + (dmg - hl) / regen[a]);
				good_ranges.push_back({tm, min(e.T, start_better)});
			}
			hl = e.H;
			tm = e.T;
		}
		if(hl <= dmg){
			if(regen[a] == 0 && inc != 0){
				cout << -1;
				return 0;
			}
			ll start_better = regen[a] == 0 ? 1000000000000ll : tm + 1 + (dmg - hl) / regen[a];
			good_ranges.push_back({tm, start_better});
		}
	}

	priority_queue<ll, vector<ll>, greater<ll>> pq;
	sort(good_ranges.begin(), good_ranges.end());

	ll ans = 0;

	for(pll p : good_ranges){
		while(!pq.empty() && pq.top() <= p.first){
			ans = max(ans, (ll)pq.size() * (ll)(bounty + inc * (pq.top() - 1)));
			pq.pop();
		}
		pq.push(p.second);
	}
	while(!pq.empty()){
		ans = max(ans, (ll)pq.size() * (ll)(bounty + inc * (pq.top() - 1)));
		pq.pop();
	}
	cout << ans;
}
