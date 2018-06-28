#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M;
int type[MAXN];
int cost[MAXN];

int incoming[MAXN];
vector<int> adj[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
	cin >> N >> M;
	for(int a = 0; a < N; a++){
		cin >> type[a];
	}
	for(int a = 0; a < M; a++){
		int x, y;
		cin >> x >> y;
		incoming[y]++;
		adj[x].push_back(y);
	}

	queue<int> q;
	for(int a = 0; a < N; a++){
		if(!incoming[a]){
			cost[a] = type[a];
			q.push(a);
		}	
	}

	while(!q.empty()){
		int fr = q.front();
		q.pop();

		for(int i : adj[fr]){
			incoming[i]--;
			if(type[fr] == 1){
				cost[i] = max(cost[i], cost[fr]);
			} else {
				cost[i] = max(cost[i], cost[fr] + type[i]);
			}

			if(!incoming[i]){
				q.push(i);
			}
		}
	}
	cout << *max_element(cost, cost + MAXN);
}
