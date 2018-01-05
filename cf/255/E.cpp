#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

ll nimv[MAXN];
ll cnt[MAXN];
set<ll> avail;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	ll N;
	cin >> N;

	vector<pll> piles;
	while(N--){
		ll x;
		cin >> x;
		piles.push_back({x, 1});
	}

	for(int a = 1; a < MAXN; a++){
		piles.push_back({a, 0});
		avail.insert(a);
	}
	cnt[0] = 1;

	ll L = 0, R = 0, xorv = 0;
	sort(piles.begin(), piles.end());
	for(pll p : piles){
		ll targR = min(p.first - 1, (ll)sqrt(p.first));
		ll targL = max(0ll, (ll)ceil(pow(p.first, 0.25)));
		ll ans;
		if(targL > targR){
			ans = 0;
		} else {
			while(R < targR){
				R++;
				if(!cnt[nimv[R]]){
					avail.erase(nimv[R]);
				}
				cnt[nimv[R]]++;
			}
			while(L < targL){
				cnt[nimv[L]]--;
				if(!cnt[nimv[L]]){
					avail.insert(nimv[L]);
				}
				L++;
			}
			ans = *avail.begin();
		}
		if(p.second == 0){
			nimv[p.first] = ans;
		} else {
			//cout << p.first << " gets " << targL << " to " << targR << endl;
			//cout << p.first << " gets " << ans << endl;
			xorv ^= ans;
		}
	}
	cout << (xorv == 0 ? "Rublo" : "Furlo");
}
