#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 5005;

int N, M; 
int type[MAXN];
string names[MAXN];
string literal[MAXN];
int args[MAXN][3];

int value[MAXN];

int tryout(int digit, int unknown) {
	int sum = 0;
	value[0] = unknown;
	for(int a = 1; a <= N; a++){
		if(type[a] == 0){
			value[a] = literal[a][digit] - '0';
		} else {
			if(args[a][1] == 1) {
				value[a] = value[args[a][0]] ^ value[args[a][2]];
			} else if (args[a][1] == 2) {
				value[a] = value[args[a][0]] | value[args[a][2]];
			} else if (args[a][1] == 3) {
				value[a] = value[args[a][0]] & value[args[a][2]];
			} else {
				//cout << "Unexpected args = " << args[a][1] << endl;
			}
		}
		//cout << "[" << a << "," << value[a] << "]";
		sum += value[a];
	}
	//cout << digit << "," << unknown << " gets " << sum << "\n";
	return sum;
}

pair<char, char> solve (int digit) {
	int sum0 = tryout(digit, 0);
	int sum1 = tryout(digit, 1);
	
	pair<char, char> p;
	p.first = sum0 <= sum1 ? '0' : '1';
	p.second = sum0 >= sum1 ? '0' : '1';

	return p;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	cin >> N >> M;

	names[0] = "?";
	for(int a = 1; a <= N; a++){
		cin >> names[a];

		string useless;
		cin >> useless;

		string tmp;
		cin >> tmp;
		if(tmp[0] == '0' || tmp[0] == '1'){
			type[a] = 0;
			literal[a] = tmp;
		} else {
			type[a] = 1;
			args[a][0] = find(names, names + a, tmp) - names;
			cin >> tmp;
			if(tmp == "XOR") args[a][1] = 1;
			if(tmp == "OR" ) args[a][1] = 2;
			if(tmp == "AND") args[a][1] = 3;

			cin >> tmp;
			args[a][2] = find(names, names + a, tmp) - names;
		}
	}

	string ans1, ans2;
	for(int a = 0; a < M; a++){
		pair<char, char> p = solve(a);
		ans1 += p.first;
		ans2 += p.second;
	}
	cout << ans1 << endl << ans2 << endl;
}
