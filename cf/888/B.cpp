#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
string str;
int U, D, L, R;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	cin >> N >> str;
	for(char c : str){
		if(c == 'U') U++;
		if(c == 'D') D++;
		if(c == 'L') L++;
		if(c == 'R') R++;
	}
	cout << 2 * min(U, D) + 2 * min(L, R);
}
