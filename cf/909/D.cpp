#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

set<pair<int, char>> points;
set<int> dividers;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    string str;
    cin >> str;
    for(int a = 0; a < (int)str.size(); a++){
        points.insert({2 * a, str[a]});
    }
	for(int a = 0; a < (int)str.size() - 1; a++){
		if(str[a] != str[a + 1]) {
			dividers.insert(2 * a + 1);
		}	
	}
	
	int ans = 0;
	while(!dividers.empty()){
		set<int> todel;
		set<pair<int, char>> todel2;
		auto iter = dividers.begin();
		while(iter != dividers.end()) {
			auto nxt = points.lower_bound({*iter, 'a'});
			if(nxt == points.end() || nxt == points.begin()){
				todel.insert(*iter);
			} else if (iter != dividers.begin() && prev(nxt)->first <= *prev(iter)) {
				todel.insert(*iter);
			} else if (prev(nxt)->second == nxt->second) {
				todel.insert(*iter);
			} else {
				todel2.insert(*nxt);
				todel2.insert(*prev(nxt));
			}
			iter++;
		}
		for(int i : todel){
			dividers.erase(i);
		}
		for(pair<int, char> p : todel2) {
			points.erase(p);
		}
		if(!todel2.empty()){
			ans++;
		}
	}
	cout << ans;
 }
