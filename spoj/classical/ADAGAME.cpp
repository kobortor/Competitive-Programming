#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int num, turns;
int res[10][10][10][10][101];

//returns true if ada wins
bool win(int a, int b, int c, int d, int t){
	if(res[a][b][c][d][t] != -1){
		return res[a][b][c][d][t];
	}
	if(t == 0){
		int val = a * 1000 + b * 100 + c * 10 + d;
		res[a][b][c][d][t] = (val > num);
		return res[a][b][c][d][t];
	}
	if((turns - t) % 2 == 0){
		res[a][b][c][d][t] = 
			win((a + 1) % 10, b, c, d, t - 1) ||
			win(a, (b + 1) % 10, c, d, t - 1) ||
			win(a, b, (c + 1) % 10, d, t - 1) ||
			win(a, b, c, (d + 1) % 10, t - 1);
	} else {
		res[a][b][c][d][t] = 
			win((a + 1) % 10, b, c, d, t - 1) &&
			win(a, (b + 1) % 10, c, d, t - 1) &&
			win(a, b, (c + 1) % 10, d, t - 1) &&
			win(a, b, c, (d + 1) % 10, t - 1);
	}
	return res[a][b][c][d][t];
}


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--){
		memset(res, -1, sizeof res);
		cin >> num >> turns;
		if(win(num / 1000, num / 100 % 10, num / 10 % 10, num % 10, turns)){
			cout << "Ada\n";
		} else {
			cout << "Vinit\n";
		}
	}
}
