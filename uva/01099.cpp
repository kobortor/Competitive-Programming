#include<bits/stdc++.h>

using namespace std;
template<typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using maxheap = priority_queue<T>;
template<typename T>
using dpair = pair<T, T>;
typedef long long ll;

const int MAXN = 15;
const int MAXW = 101;
const int MAXH = 101;

int N, W, H;
int friends[MAXN];
int dp[MAXW][1 << MAXN];
int remain_cost(int v) {
	int ans = 0;
	for (int a = 0; a < N; a++) {
		if ((v & (1<<a)) == 0) {
			ans += friends[a];
		}
	}
	return ans;
}

vector<int> get_states(int state) {
	vector<int> extras;
	for (int a = 0; a < N; a++) {
		if ((state & (1 << a)) == 0) {
			extras.push_back(a);
		}
	}
	vector<int> ans;
	for (int a = 0; a < (1 << extras.size()); a++) {
		int val = state;
		for (int b = 0; b < extras.size(); b++) {
			if (a & (1 << b)) {
				val |= (1 << extras[b]);
			}
		}
		ans.push_back(val);
	}
	return ans;
}

//returns true if possible
bool solve(int wid, int ht, int state) {
	int rem_cost = remain_cost(state);
	if (rem_cost != wid * ht) {
		return false;
	}
	if (dp[wid][state] != -1) {
		return dp[wid][state];
	}
	dp[wid][state] = false;

	int remain = (~state) & ((1 << N) - 1);
	if ((remain & -remain) == remain) {
		//last piece
		//printf("dp[%lld][%lld] = true\n", wid, state);
		return dp[wid][state] = true;
	}

	vector<int> states = get_states(state);
	for (int s : states) {
		int cost = remain_cost(s);
		if (cost == 0 || cost == wid * ht) {
			continue;
		}
		int other_state = (~s | state) & ((1 << N) - 1);
		if (cost % wid == 0) {
			if (solve(wid, cost / wid, s) && solve(wid, ht - cost / wid, other_state)) {
				return dp[wid][state] = true;
			}
		}
		if (cost % ht == 0) {
			if (solve(cost / ht, ht, s) && solve(wid - cost / ht, ht, other_state)) {
				return dp[wid][state] = true;
			}
		}
	}
	return dp[wid][state] = false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("text.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	cin.tie(0);
	cin.sync_with_stdio(0);
#endif
	for (int test = 1; true; test++) {
		cin >> N;
		if (N == 0) {
			break;
		}
		cin >> W >> H;
		for (int a = 0; a < N; a++) {
			cin >> friends[a];
		}

		memset(dp, -1, sizeof(dp));
		bool ans = solve(W, H, 0);
		cout << "Case " << test << ": ";
		if (ans) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}