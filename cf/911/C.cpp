#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int cnt[1505];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
	for(int a = 0; a < 3; a++){
		int k;
		cin >> k;
		cnt[k]++;
	}

	if(cnt[1] >= 1 || cnt[2] >= 2 || cnt[3] >= 3 || (cnt[2] == 1 && cnt[4] == 2)){
		cout << "YES";
	} else {
		cout << "NO";
	}
}
