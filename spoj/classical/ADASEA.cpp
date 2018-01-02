#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int T;
char grid[MAXN][MAXN];
int N, M;

int dfs(int r, int c){
	if(r < 0 || c < 0 || r == N || c == M || grid[r][c] != '#'){
		return 0;
	}
	grid[r][c] = '~';
	return 1 + dfs(r + 1, c) + dfs(r - 1, c) + dfs(r, c - 1) + dfs(r, c + 1);
}

ll gcd(ll a, ll b){
	while(a % b){
		a %= b;
		swap(a, b);
	}
	return b;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
	cin >> T;
	while(T--){
		cin >> N >> M;
		for(int a = 0; a < N; a++){
			cin >> grid[a];
		}
		ll top = 0, bottom = N * M;
		for(int a = 0; a < N; a++){
			for(int b = 0; b < M; b++){
				if(grid[a][b] == '#'){
					ll x = dfs(a, b);
					top += x * x;
				}
			}
		}
		if(top % bottom == 0){
			cout << top / bottom;
		} else {
			ll g = gcd(top, bottom);
			cout << top / g << " / " << bottom / g;
		}
		if(T != 0){
			cout << "\n";
		}
	}
}
