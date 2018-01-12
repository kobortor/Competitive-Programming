#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int freq[26];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

	int N;
	string str;
	cin >> N >> str;
	for(char c : str){
		freq[c - 'a']++;
	}
	for(char c : str){
		if(freq[c - 'a'] == 1){
			cout << c;
			return 0;
		}
	}
	cout << -1;
}
