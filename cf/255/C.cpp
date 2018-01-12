#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 4005;

int N;
int arr[MAXN];
vector<int> uniq;

int dp[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	cin >> N;
	for(int a = 0; a < N; a++){
		cin >> arr[a];
		uniq.push_back(arr[a]);
	}
	sort(uniq.begin(), uniq.end());
	uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());

	for(int a = 0; a < N; a++){
		arr[a] = lower_bound(uniq.begin(), uniq.end(), arr[a]) - uniq.begin();
		for(int b = 0; b < N; b++){
			dp[arr[a]][b] = max(dp[b][arr[a]] + 1, dp[arr[a]][b]);
		}
	}
	int best = 0;
	for(int a = 0; a < N; a++){
		for(int b = 0; b < N; b++){
			best = max(best, dp[a][b]);
		}
	}
	cout << best;
}
