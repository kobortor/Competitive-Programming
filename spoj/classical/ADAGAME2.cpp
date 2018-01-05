#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int T;

int nimv[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	cin >> T;
	while(T--){
		int N, M;
		cin >> N >> M;
		vector<int> rules;
		while(M--){
			int x;
			cin >> x;
			rules.push_back(x);
		}

		for(int a = 1; a < MAXN; a++){
			bitset<32> nimbers;
			for(int i : rules){
				if(a - i >= 0){
					nimbers[nimv[a - i]] = true;
				}
			}

			int mex = 0;
			while(nimbers[mex]){
				mex++;
			}
			nimv[a] = mex;
		}

		int xorv = 0;
		while(N--){
			int x;
			cin >> x;
			xorv ^= nimv[x];
		}
		cout << (xorv == 0 ? "Vinit\n" : "Ada\n");
	}
}
