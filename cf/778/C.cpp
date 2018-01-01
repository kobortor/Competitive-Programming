#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 6e5 + 5;

int saving[MAXN];
int N;

struct node {
	int child[26];
	int sz;
} tree[MAXN];

void size_dfs(int pos){
	tree[pos].sz = 1;
	for(int i = 0; i < 26; i++){
		if(tree[pos].child[i] != -1){
			size_dfs(tree[pos].child[i]);
			tree[pos].sz += tree[tree[pos].child[i]].sz;
		}
	}
}

int scnt;
int saved = 0;
vector<pii> toclear;

void join(int src, int targ){
	for(int i = 0; i < 26; i++){
		if(tree[targ].child[i] != -1){
			if (tree[src].child[i] == -1) {
				toclear.push_back({src, i});
				tree[src].child[i] = scnt++;
			} else {
				saved++;
			}
			join(tree[src].child[i], tree[targ].child[i]);
		}
	}
}

void solve_dfs(int pos, int lvl){
	int best = -1;
	saved = 0;
	scnt = N + 1;

	for(int i = 0; i < 26; i++){
		if(tree[pos].child[i] != -1) {
			if (best == -1 || tree[tree[pos].child[i]].sz > tree[tree[pos].child[best]].sz) {
				best = i;
			}
		}
	}

	for(int i = 0; i < 26; i++){
		if(tree[pos].child[i] != -1 && i != best){
			join(tree[pos].child[best], tree[pos].child[i]);
			saved++;
		}
	}

	while(scnt > N + 1){
		memset((void*)&tree[scnt], -1, sizeof tree[scnt]);
		scnt--;
	}
	for(pii p : toclear){
		tree[p.first].child[p.second] = -1;
	}

	toclear.clear();

	if(best != -1) {
		saved++;
	}

	saving[lvl] += saved;

	for(int i = 0; i < 26; i++){
		if(tree[pos].child[i] != -1){
			solve_dfs(tree[pos].child[i], lvl + 1);
		}
	}
}


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	memset(tree, -1, sizeof tree);

	cin >> N;
	scnt = N + 1;
	for(int a = 0; a < N - 1; a++){
		int x, y;
		char c;
		cin >> x >> y >> c;
		
		tree[x].child[c - 'a'] = y;
	}
	size_dfs(1);
	solve_dfs(1, 1);
	
	int best_idx = 1;
	for(int a = 2; a <= N; a++){
		if(saving[a] > saving[best_idx]){
			best_idx = a;
		}
	}

	cout << N - saving[best_idx] << "\n";
	cout << best_idx << "\n";
}
