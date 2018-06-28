#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	ll N, X, Y;
	cin >> N >> X >> Y;

	if(Y < N){
		cout << -1;
		return 0;
	}
	if((Y - N + 1) * (Y - N + 1) + (N - 1) >= X){
		cout << Y - N + 1 << "\n";
		for(int a = 2; a <= N; a++){
			cout << 1 << "\n";
		}
	} else {
		cout << -1;
	}
}
