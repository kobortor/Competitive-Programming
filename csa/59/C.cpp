#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3005;

int N;
char tri[MAXN][MAXN];

string output;
vector<pii> spots;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	cin >> N;
	for(int a = 1; a <= N; a++){
		cin >> (tri[a] + 1);
	}

	spots.push_back({1, 1});
	output += tri[1][1];

	for(int a = 1; a < N; a++){
		vector<pii> possible;
		char best = 'z';

		for(pii p : spots){
			possible.push_back({p.first + 1, p.second});
			possible.push_back({p.first + 1, p.second + 1});

			best = min(best, tri[p.first + 1][p.second]);
			best = min(best, tri[p.first + 1][p.second + 1]);
		}

		spots.clear();
		for(pii p : possible){
			if(tri[p.first][p.second] == best){
				spots.push_back(p);
				tri[p.first][p.second] = '~'; //dummy
			}
		}
		output += best;
	}
	cout << output;
}
