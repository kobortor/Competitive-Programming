#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

int N;

#define allof(x) x.begin(), x.end()

vector<pll> to_add;

struct BIT{
	ll data[MAXN];
	void update(int pos, ll val){
		while(pos < MAXN){
			data[pos] += val;
			pos += pos & -pos;
		}
	}
	ll query(int pos){
		ll ans = 0;
		while(pos){
			ans += data[pos];
			pos -= pos & -pos;
		}
		return ans;
	}
}ds;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
	cin >> N;

	set<int> missing = {0, N + 1};
	for(int a = 1; a <= N; a++){
		ll x;
		cin >> x;
		to_add.push_back({x, a});
		missing.insert(a);
	}

	ll ans = 0;
	sort(allof(to_add));
	for(pll p : to_add){
		auto iter = missing.find(p.second);
		ll prv = *prev(iter);
		ll nxt = *next(iter);

		ans += (p.second - prv) * (nxt - p.second) * p.first;
		missing.erase(iter);
	}
	for(int a = 1; a <= N; a++){
		missing.insert(a);
	}
	reverse(allof(to_add));
	for(pll p : to_add){
		auto iter = missing.find(p.second);
		ll prv = *prev(iter);
		ll nxt = *next(iter);

		ans -= (p.second - prv) * (nxt - p.second) * p.first;
		missing.erase(iter);
	}
	cout << ans;
}
