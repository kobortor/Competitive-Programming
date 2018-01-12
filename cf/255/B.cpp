#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	string str;
	cin >> str;

	int numx = 0, numy = 0;
	for(char c : str){
		if(c == 'x'){
			numx++;
		} else {
			numy++;
		}
	}
	for(int a = numx; a < numy; a++){
		cout << 'y';
	}
	for(int a = numy; a < numx; a++){
		cout << 'x';
	}
}
