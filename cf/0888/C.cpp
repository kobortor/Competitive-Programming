#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string str;

int prv[26];
bool good[26];

bool is_good(int K){
	memset(prv, -1, sizeof prv);
	memset(good, true, sizeof good);

	for(int a = 0; a < (int)str.size(); a++){
		if(a - prv[str[a] - 'a'] > K){
			good[str[a] - 'a'] = false;
		}

		prv[str[a] - 'a'] = a;
	}
	for(int a = 0; a < 26; a++){
		if(good[a] && (int)str.size() - prv[a] <= K){
			return true;
		}
	}
	return false;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	cin >> str;
	int lo = 1, hi = (int)str.size();
	while(lo <= hi){
		int mid = (lo + hi) / 2;
		if(is_good(mid)){
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout << lo;
}
