#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	cin >> N;
	
	int v0, v1, v2;
	cin >> v0 >> v1;

	int ans = 0;

	for(int a = 3; a <= N; a++){
		cin >> v2;
		if(v0 > v1 && v1 < v2){
			ans++;
		}
		if(v0 < v1 && v1 > v2){
			ans++;
		}

		v0 = v1;
		v1 = v2;
	}
	cout << ans;
}
