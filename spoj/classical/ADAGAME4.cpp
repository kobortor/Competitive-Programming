#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e7 + 7;
int ndivisors[MAXN];
bool adawin[MAXN];
int prvloss;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	ndivisors[1] = 1;
	for(int a = 2; a < MAXN; a++){
		ndivisors[a] = 1;
	}
	for(int a = 2; a < MAXN; a++){
		if(ndivisors[a] == 1){
			for(int b = a; b < MAXN; b += a){
				int num = b, cnt = 0;
				while(num % a == 0){
					num /= a;
					cnt++;
				}
				//cout << a << " goes into " << b << " " << cnt << " times\n";
				ndivisors[b] *= cnt + 1;
			}
		}
		//cout << a << " has " << ndivisors[a] << "\n";
	}
	prvloss = 0;

	for(int a = 1; a < MAXN; a++){
		if(a - prvloss > ndivisors[a]){
			prvloss = a;
		} else {
			adawin[a] = true;
		}
	}

	int T;
	cin >> T;
	while(T--){
		int x;
		cin >> x;
		if(adawin[x]){
			cout << "Ada\n";
		} else {
			cout << "Vinit\n";
		}
	}
}
