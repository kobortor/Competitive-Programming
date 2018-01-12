#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	ll G1, P1, G2, P2;
	cin >> G1 >> P1 >> G2 >> P2;
	ll W1 = -1, W2 = -1;
	for(int w = 0; W1 == -1 || W2 == -1; w++){
		if(W1 == -1 && w * 100 / G1 == P1){
			W1 = w;
		}
		if(W2 == -1 && w * 100 / G2 > P2){
			W2 = w - 1;
		}
	}
	cout << min(G2 - G1, W2 - W1) << "\n";
}
