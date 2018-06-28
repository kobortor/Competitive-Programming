#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 36;

int N, M;

ll arr[MAXN];

void get_sums(vector<ll> nums, vector<ll> &sums){
	for(int a = 0; a < (1 << nums.size()); a++){
		ll sum = 0;
		for(int b = 0; b < (int)nums.size(); b++){
			if(a & (1 << b)){
				sum += nums[b];
			}
		}
		sums.push_back(sum % M);
	}
}


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	cin >> N >> M;
	vector<ll> v0, v1;
	for(int a = 0; a < N; a++){
		ll x;
		cin >> x;
		(a % 2 ? v0 : v1).push_back(x);
	}
	vector<ll> s0, s1;
	get_sums(v0, s0);
	get_sums(v1, s1);
	
	s1.push_back(0);
	sort(s1.begin(), s1.end());

	ll ans = 0;
	for(ll x : s0){
		//add the last thing in the range [0, M - x)
		auto iter = lower_bound(s1.begin(), s1.end(), M - x);
		ans = max(ans, x + *prev(iter));
	}
	cout << ans;
}
