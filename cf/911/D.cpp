#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1505;
int N;
int perm[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
	cin >> N;

	int inv = 0;
	for(int a = 0; a < N; a++){
		cin >> perm[a];
		for(int b = 0; b < a; b++){
			if(perm[b] > perm[a]){
				inv ^= 1;
			}
		}
	}
	int Q;
	cin >> Q;
	while(Q--){
		int l, r;
		cin >> l >> r;
		int diff = r - l;
		if(diff * (diff + 1) / 2 % 2 == 1){
			inv ^= 1;
		}
		if(inv % 2 == 1) {
			cout << "odd\n";
		} else {
			cout << "even\n";
		}
	}
}
