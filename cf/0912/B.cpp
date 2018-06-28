#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int ilog2(ll N){
    int ans = 0;
    while(N > 1){
        ans++;
        N >>= 1;
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	ll N, K;
	cin >> N >> K;
	if(K == 1){
		cout << N;
	} else {
		cout << (2ll << ilog2(N)) - 1;
	}
}
