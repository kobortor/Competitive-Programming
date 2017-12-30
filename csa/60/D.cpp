#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<pair<ll, pll>> found[2];

vector<ll> avail;
ll used = 0;
ll sum = 0;
ll num_used = 0;
ll type = 0;

void solve(int pos) {
	if(pos == (int)avail.size()){
		found[type].push_back({sum, {num_used, used}});
	} else {
		used |= 1 << pos;
		num_used++;
		sum += avail[pos];

		solve(pos + 1);

		used &= ~(1 << pos);
		num_used--;
		sum -= avail[pos];

		solve(pos + 1);
	}
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	int N;
	cin >> N;
	vector<ll> arr;

	ll orig = 0;
	for(int a = 0; a < N; a++){
		ll x, y;
		cin >> x >> y;
		arr.push_back(-(x + y));
		orig += x;
	}

	for(int a = 0; a < N / 2; a++){
		avail.push_back(arr[a]);
	}
	solve(0);

	avail.clear();
	type = 1;
	for(int a = N / 2; a < N; a++){
		avail.push_back(arr[a]);
	}
	
	solve(0);

	sort(found[0].begin(), found[0].end());
	sort(found[1].begin(), found[1].end());
	reverse(found[1].begin(), found[1].end());

	ll best = -1;
	ll bestdiff = 999;

	int vidx = 0;

	for(auto &au : found[0]){
		while(	vidx + 1 < (int)found[1].size()) {
			bool good = false;
			good |= (orig + found[1][vidx].first + au.first > 0);
			good |= (orig + found[1][vidx + 1].first + au.first == 0) &&
			 		abs(N / 2 - found[1][vidx + 1].second.first - au.second.first) <= abs(N / 2 - found[1][vidx].second.first - au.second.first);
			if(good) vidx++;
			else break;
		}

		if(orig + found[1][vidx].first + au.first != 0){
			continue;
		}

		int diff = abs((N + 1) / 2 - found[1][vidx].second.first - au.second.first);
		if(diff < bestdiff){
			bestdiff = diff;
			best = au.second.second | (found[1][vidx].second.second << (N / 2));
		}
	}
	if(bestdiff == 999){
		cout << -1;
		return 0;
	} else {
		// cout << bestdiff << "\n";
		for(int a = 0; a < N; a++){
			cout << (best >> a) % 2;
		}
	}	
}
