#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

string str, targ;
int rem[MAXN];

bool good(int steps) {
	int idx = 0;
	for(int a = 0; a < (int)str.size(); a++) {
		if(rem[a] > steps) {
			if(str[a] == targ[idx]) {
				idx++;
				if(idx == (int)targ.size()){
					return true;
				}
			}
		}
	}
	return false;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
	cin >> str >> targ;
	for(int a = 0; a < (int)str.size(); a++){
		int x;
		cin >> x;
		rem[x - 1] = a + 1;
	}
	int lo = 0, hi = str.size();
	while(lo <= hi) {
		int mid = (lo + hi) / 2;
		if(good(mid)){
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	cout << lo - 1;
}
