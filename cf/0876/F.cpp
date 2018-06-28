#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

#define all_of(x) x.begin(), x.end()

int prv_bit[32];
int arr[MAXN];
vector<pii> decrease;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
	int N;
	cin >> N;

	decrease.push_back({0x3fffffff, 0});
	ll ans = 0;
	for(int a = 1; a <= N; a++){
		cin >> arr[a];

		for(int b = 0; b < 32; b++){
			if(arr[a] & (1 << b)){
				prv_bit[b] = a;
			}
		}
		vector<int> uniq;
		for(int a = 0; a < 32; a++){
			uniq.push_back(prv_bit[a]);
		}	
		uniq.push_back(a);
		sort(all_of(uniq));
		uniq.erase(unique(all_of(uniq)), uniq.end());
		reverse(all_of(uniq));

		int orv = arr[a];
		for(int b = 1; b < (int)uniq.size(); b++){
			if(orv > arr[a]){
				int first_good = prev(lower_bound(all_of(decrease), pii(orv - 1, 0x3fffffff), greater<pii>()))->second + 1;
				first_good = max(first_good, uniq[b] + 1);
				first_good = min(first_good, uniq[b - 1] + 1);
				ans += uniq[b - 1] - first_good + 1;
			}
			orv |= arr[uniq[b]];
		}
	
		while(decrease.back().first < arr[a]){
			decrease.pop_back();
		}
		decrease.push_back(pii(arr[a], a));
	}
	cout << ans;
}
