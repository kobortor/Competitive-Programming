#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5005;

int N;
int arr[MAXN];
int dp[MAXN];
int cnt[MAXN];
int used[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
	
	cin >> N;
	for(int a = 1; a <= N; a++){
		cin >> arr[a];
		cnt[arr[a]]++;
	}

	for(int a = 1; a <= N; a++){
		dp[a] = dp[a - 1];
		int error = 0;
		int xorv = 0;

		for(int b = a; b >= 1; b--){
			if(used[arr[b]] == 0){
				xorv ^= arr[b];
				error++;
			}
			used[arr[b]]++;
			if(used[arr[b]] == cnt[arr[b]]){
				error--;
			}
			if(error == 0){
				dp[a] = max(dp[a], xorv + dp[b - 1]);
			}
		}
		fill(used, used + MAXN, 0);
	}
	cout << dp[N];

}
